#include "String.h"
#include <string>
int main() {
    String s = "Hello ";
    String s1 = "World!";
    String s2 = s;
    String s3 = s2 + s1;
    std::string s4 = "Hello World!";
    int len = s3.getLength();
    cout << s << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    cout << len << endl;
    cout << s4 << endl;
    cout << s4.size() << endl;
}