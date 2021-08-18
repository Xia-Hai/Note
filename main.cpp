#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
void creat(TreeNode* &p) {
    int a;
    cin >> a;
    if (a == 0) {
        p = nullptr;
    }
    else {
        p = new TreeNode(a);
        creat(p->left);
        creat(p->right);
    }
}
int treeDepth(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        else {
            int m = treeDepth(root->left);
            int n = treeDepth(root->right);
            return m >= n ? (m + 1) : (n + 1);
        }
}
void preorder(TreeNode *root) {
    if (root == nullptr) {
        return;
    }
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}
void level(TreeNode *root, int l, vector<vector<int>> &result) {
    if (root == nullptr) {
        return;
    }
    //cout << root->val << " ";
    result[l].push_back(root->val);
    level(root->left, l + 1, result);
    level(root->right, l + 1, result);
}
int main() {
    TreeNode *root = nullptr;
    creat(root);
    preorder(root);
    cout << endl;
    int l = treeDepth(root);
    cout << l << endl;
    vector<vector<int>> result(l);
    level(root, 0, result);
    for (auto &a : result) {
        for (auto & b : a) {
            cout << b << " ";
        }
        cout << endl;
    }
    return 0;

}

// void reverse(string &s, int i, int j) {
//     while (i < j) {
//         swap(s[i], s[j]);
//         i++;
//         j--;
//     }
// }
// void removeSpace (string &s) {
//     int fast = 0;
//     int slow = 0;
//     int size = (int)s.size();
//     //移除最前面的空格
//     while (fast < size && s[fast] == ' ') {
//         fast++;
//     }
//     //移除连续的空格
//     for (; fast < size; fast++) {
//         if (fast - 1 > 0 && s[fast] == ' ' && s[fast - 1] == ' ') {
//             continue;
//         }
//         else {
//             s[slow++] = s[fast];
//         }
//     }
//     //移除最后的空格
//     if (slow - 1 > 0 && s[slow - 1] == ' ') {
//         s.resize(slow - 1);
//     }
//     else {
//         s.resize(slow);
//     }
// }


// string& reverseString(string &s) {
//     //完全反转
//     reverse(s.begin(), s.end());
//     removeSpace(s);
//     for (int i = 0; i < s.size(); i++) {
//         int j = i;
//         while (j < s.size() && s[j] != ' ') {
//             j++;
//         }
//         reverse(s, i, j - 1);
//         i = j;
//     }
//     return s;
// }

// int main() {
//     string s = "     hello     world      ";
//     // string s1 = reverseString(s);
//     //cout << s1 << endl;
//     reverseString(s);

//     cout << s << endl;

    
//     return 0;
// }








// struct TreeNode {
//     int val;
//     TreeNode *root;
//     TreeNode *left;
//     TreeNode *right;
// };

// class Solution {
// public:
//     vector<int> preorderTraversal(TreeNode *root) {
//     vector<int> result;
//     TreeNode tree;
//     stack<TreeNode*> st;
//     if (root == nullptr) 
//         return result;
   
//     st.push(root);
//     while (!st.empty()) {
//         TreeNode *node = st.top();
//         if (node != nullptr) {
//         st.pop();
//         if (node->right)  st.push(node->right);
//         if (node->left)   st.push(node->left);
//         st.push(node);
//         st.push(nullptr);
//         } else {
//             st.pop();//空指针出栈
//             node = st.top();
//             st.pop();
//             result.push_back(node->val);   
//     }   

//     }
//     return result;
//     }
    
// };
// class Solution {
// public:
//     vector<int> postorderTraversal(TreeNode *root) {
//         vector<int> result;
//         stack<TreeNode*> st;
//         if (root != nullptr) {
//             st.push(root);
//         }
//         while (!st.empty()) {
//             TreeNode *node = st.top();
//             if (node != nullptr) {
//                 st.pop();
//                 st.push(node);
//                 st.push(nullptr);
//                 if (node->right) st.push(node->right);
//                 if (node->left) st.push(node->left);
//             } else {
//                 st.pop();
//                 node = st.top();
//                 st.pop();
//                 result.push_back(node->val);
//             }
//         }                                                                
//         return result;
//     }
// };

// class Solution {
// public:
//     vector<int> postorderTraversal(TreeNode *root) {
//         vector<int> result;
//         stack<TreeNode*> st;
//         TreeNode *cur = root, *pre = nullptr;
//         while (cur || !st.empty()) {
//             if (cur) {
//                 st.push(cur);
//                 cur = cur->left;
//             }
//             else {
//                 cur = st.top();
//                 if (cur->right != nullptr && cur->right != pre) {
//                     cur = cur->right;
//                 }
//                 else {
//                     cur = st.top();
//                     st.pop();
//                     result.push_back(cur->val);
//                     pre = cur;
//                     cur = nullptr;
//                 }
//             }

//         }
//         return result;
//     }
// };
// class Solution {
// public:
//     vector<int> preorderTraversal(TreeNode *root) {

//         vector<int> result;
//         stack<TreeNode*> st;
//         TreeNode *cur = root;
//         if (cur != nullptr) {
//             st.push(cur);
//         }
//         while (!st.empty()) {
//             cur = st.top();
//             result.push_back(cur->val);
//             st.pop();
//             if (cur->right) {
//                 st.push(cur->right);
//             }
//             if (cur->left) {
//                 st.push(cur->left);
//             }
//         }
//         return result;
//     }
// };
// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode *root) {
//         vector<int> result;
//         stack<TreeNode*> st;
//         TreeNode *cur = root;
//         while (cur || !st.empty()) {
//             if (cur) {
//                 st.push(cur);
//                 cur = cur->left;
//             }
//             else {
//                 cur = st.top();
//                 result.push_back(cur->val);
//                 st.pop();
//                 cur = cur->right;
//             }
//         }
//         return result;
//     }
// };



// //KMP算法
// void getNext(vector<int> &next, string &needle) {
//     int j = 0;
//     next[0] = 0;
//     for (int i = 1; i < needle.size(); i++) {
//         while (j > 0 && needle[i] != needle[j]) {
//             j = next[j - 1];
//         }
//         if (needle[i] == needle[j]) {
//             j++;
//         }
//         next[i] = j;
//     }
// }

// int strStr(string &haystack, string &needle) {
//     if (needle.size() == 0) {
//         return 0;
//     }
//     int j = 0;
//     vector<int> next(needle.size());
//     getNext(next, needle);
//     for (int i = 0; i < haystack.size(); i++) {
//         while (j > 0 && haystack[i] != needle[j]) {
//             j = next[j - 1];
//         }
//         if (haystack[i] == needle[j]) {
//             j++;
//         }
//         if (j == needle.size()) {
//             return i - needle.size() + 1;
//         }
//     }
//     return -1;
// }
        
   
// int main() {
//     string haystack = "abacabfg";
//     string needle = "cabf";
//     int result = strStr(haystack, needle);
//     cout << result << endl;
//     return 0;
// }



// int main()
// {
//     char a = 'a';
//     string s;
//     vector<string> ss;
//     s.push_back('a' + 1);
//     ss.emplace_back(s);
//     cout << s << endl;
//     for(auto &s : ss)
//         cout << s << ' ';
//     cout << endl;
// }



// typedef int(*Func)(int, int);

// int func(int m, int n)
// {
//     return m + n;
// }
// // void test(int m, int n, Func func)//函数指针
// // {
// //     int result = func(m, n);
// //     cout << result << endl;
// // }
// template<typename T, typename F>
// void test(const T &a, const T &b, F func)
// {
//     cout << func(a, b) << endl;
// }
// class A {
// public:
//     A() {
//         cout << "构造函数调用" << endl;
//     };
//     A(const A &a) {
//         cout << "拷贝构造函数调用" << endl;
//     }
//     int operator()(int n, int m) { //对象通过重载（）变为可调用对象，可以像函数一样使用
//        return n + m;
//     }
// };

// int main()
// {
//     //A a;
//     test(20, 20, A());
//     return 0;
// }