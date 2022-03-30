#include <iostream>
#include <atomic>

class RefCount {
public:
    RefCount() : refer(0) {}
    ~RefCount() {
        this->decrementRef();
    }
    void incrementRef() {
        refer++;
    }
    int use_count() {
        return refer;
    }
    bool decrementRef() {
        if (--refer == 0) {
            delete this;
            return true;
        }
        return false;
    }
private:
    std::atomic<int> refer;
};
template<typename T>
class SharedPtr {
public:
    SharedPtr() : ptr(nullptr), ref(new RefCount) {
        if (ref) ref->incrementRef();
    };
    explicit SharedPtr(T *ptr_) : ptr(ptr_), ref(new RefCount) {
        if (ref != nullptr) {
            ref->incrementRef();
        }
    }
    SharedPtr(const SharedPtr &other) : ptr(other.ptr), ref(other.ref) {
        if (ref) {
            ref->incrementRef();
        }
    }
    SharedPtr(SharedPtr &&other) noexcept {
        ptr = other.ptr;
        ref = other.ref;
        other.ptr = nullptr;
        other.ref = nullptr;
    }
    SharedPtr &operator=(const SharedPtr &other) {
        if (this == &other || *this == other) {
            return *this;
        }
        reset();
        ptr = other.ptr;
        ref = other.ref;
        ref->incrementRef();
        return *this;
    }

    SharedPtr &operator=(SharedPtr &&other) noexcept {
        if (this == &other || *this == other) {
            return *this;
        }
        reset();
        ptr = other.ptr;
        ref = other.ref;
        other.ptr = nullptr;
        other.ref = nullptr;
        return *this;
    }
    ~SharedPtr() {
        if (ref) {
            this->decrementRef();
        }
    }
    T &operator*() const {
        return *ptr;
    }
    T *operator->() const {
        return ptr;
    }

    T *get() const {
        return ptr;
    }
    void reset() {
        if (ptr) {
            this->decrementRef();
        }
    }
    void decrementRef() {
        if (ref && ptr) {
            if (ref->decrementRef()) {
                delete ptr;
                ptr = nullptr;
            }
        }
    }

    int use_count() {
        return ref->use_count();
    }

    bool unique() {
        return use_count() == 1;
    }

    void swap(SharedPtr &other) {
        std::swap(ptr, other.ptr);
        std::swap(ref, other.ref);
    }

    friend inline bool operator==(const SharedPtr &lhs, const SharedPtr &rhs) {
        return lhs.ptr == rhs.ptr;
    }
    friend inline bool operator<(const SharedPtr &lhs, const SharedPtr &rhs) {
        return lhs.ptr < rhs.ptr;
    }

private:
    T *ptr;
    RefCount *ref;
};


int main() {
    SharedPtr<int> ptr(new int);
    SharedPtr<int> ptr2(ptr);
    SharedPtr<int> ptr3(std::move(ptr));
    SharedPtr<int> ptr4 = ptr2;
    SharedPtr<int> ptr5;
    ptr5 = std::move(ptr3);
    std::cout << ptr5.use_count() << std::endl;
    SharedPtr<int> ptr6(new int(6));
    ptr5.swap(ptr6);
    std::cout << ptr5.use_count() << std::endl;
    return 0;
}
