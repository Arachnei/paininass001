#pragma warning(disable:4996)
#ifndef MyString_H
#include <iostream>
#include <cstring>
#include <cassert>

namespace cs_mystring {

    class MyString {
    private:
        char* myeowString;

    public:
        MyString();
        MyString(const char* givenCString);
        MyString(const MyString& givenMyString);
        ~MyString();

        MyString& operator=(const MyString& assignMyString);

        const char* returnMyeowString() const {
            return myeowString;
            }

        static const int MAX_INPUT_SIZE = 127;

        int length() const;

        MyString(char* value) : myeowString(value) {}

        char operator[](int index) const;
        char& operator[](int index);
    };

    bool operator<(const MyString& firstMyString, const MyString& secondMyString);

    bool operator<=(const MyString& firstMyString, const MyString& secondMyString);

    bool operator>(const MyString& firstMyString, const MyString& secondMyString);

    bool operator>=(const MyString& firstMyString, const MyString& secondMyString);

    bool operator==(const MyString& firstMyString, const MyString& secondMyString);

    bool operator!=(const MyString& firstMyString, const MyString& secondMyString);

    std::ostream& operator<<(std::ostream& outPut, const MyString& givenMyString);

    std::istream& operator>>(std::istream& in, const MyString& target);

}

#endif
