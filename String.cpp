#include "String.h"
#include <cstring>
//using namespace std;

String::String(const char *str) {
    if (str == nullptr) {
        m_data = new char[1];
        *m_data = '\0';//对空的字符串进行处理
    } else {
        int length = strlen(str);
        m_data = new char(length + 1);
        strcpy(m_data,str);
    }
}

String::~String() {
    if (m_data != nullptr) {
        delete [] m_data;
        m_data = nullptr;
    }
}

String::String(const String &other) {
    m_data = new char(strlen(other.m_data) + 1);
    strcpy(m_data, other.m_data);
}

String &String::operator=(const String &other) {
    //注意防止自赋值的情况
    if (this == &other) {
        return *this;
    }
    delete [] m_data;
    m_data = new char(strlen(other.m_data) + 1);
    strcpy(m_data, other.m_data);
    return *this;  
}

 String &String::operator=(const char *s) {
     delete [] m_data;
     m_data = new char(strlen(s) + 1);
     strcpy(m_data, s);
     return *this;
 }

 String String::operator+(const String &other) {
     String newstring;
     if (other.m_data == nullptr) newstring = *this;
     else if (this->m_data == nullptr) newstring = other;
     else {
         newstring.m_data = new char(strlen(this->m_data) +
                        strlen(other.m_data) + 1);
         strcpy(newstring.m_data, m_data);
         strcat(newstring.m_data, other.m_data);
     }
     return newstring;
 }

 bool String::operator==(const String &other) {
     if (m_data != other.m_data) return false;
     else {
         return strcmp(m_data, other.m_data) ? false : true;
     }
 }

 int String::getLength() {
     return strlen(this->m_data);
 }

 ostream &operator<<(ostream &os, const String &s) {
     os << s.m_data;
     return os;
 }