#ifndef _STRING_H_
#define _STRING_H_

#include <iostream>

using namespace std;

class String {
public:
    String(const char *str = nullptr);
    String(const String &other);
    ~String();
    String &operator=(const String &other);
    String &operator=(const char *s);
    String operator+(const String &other);
    bool operator==(const String &other);
    int getLength();//�����ַ����ĳ���

    friend ostream &operator<<(ostream &os, const String &s);
private:
    char *m_data;
};

#endif