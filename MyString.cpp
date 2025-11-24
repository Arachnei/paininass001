#pragma warning(disable:4996)
#include <iostream>
#include <istream>
#include <cstring>
#include "MyString.h"
#include <cassert>

namespace cs_mystring {

    MyString::MyString() {
        myeowString = new char[1];
        myeowString[0] = '\0';
    }





    MyString::MyString(const char* givenCString) {

        if (givenCString == nullptr) {
            myeowString = new char[1];
            myeowString[0] = '\0';
        }

        else {
            myeowString = new char[strlen(givenCString) + 1];
            strcpy(myeowString, givenCString);
        }
    }






    MyString::MyString(const MyString& givenMyString) {
        myeowString = new char[strlen(givenMyString.myeowString) + 1];
        strcpy(myeowString, givenMyString.myeowString);
    }






    MyString::~MyString() {
        delete[] myeowString;
    }







    MyString& MyString::operator=(const MyString& assignMyString) {
        if (this != &assignMyString) {
            delete[] myeowString;
            myeowString = new char[strlen(assignMyString.myeowString) + 1];
            strcpy(myeowString, assignMyString.myeowString);
        }
        return *this;
    }







    int MyString::length() const {
        return strlen(myeowString);
    }






    char MyString::operator[](int index) const {
        assert(index >= 0 && index < length());
        return myeowString[index];
    }






    char& MyString::operator[](int index) {
        assert(index >= 0 && index < length());
        return myeowString[index];
    }




    bool operator<(const MyString& firstMyString, const MyString& secondMyString) {
        return strcmp(firstMyString.returnMyeowString(), secondMyString.returnMyeowString()) < 0;
    }





    bool operator<(const MyString& givenMyString, const char* givenCString) {
        return strcmp(givenMyString.returnMyeowString(), givenCString) < 0;
    }





    bool operator<(const char* givenCString, const MyString& givenMyString) {
        return strcmp(givenCString, givenMyString.returnMyeowString()) < 0;
    }






    bool operator<=(const MyString& firstMyString, const MyString& secondMyString) {
        return strcmp(firstMyString.returnMyeowString(), secondMyString.returnMyeowString()) <= 0;
    }






    bool operator<=(const MyString& givenMyString, const char* givenCString) {
        return strcmp(givenMyString.returnMyeowString(), givenCString) <= 0;
    }






    bool operator<=(const char* givenCString, const MyString& givenMyString) {
        return strcmp(givenCString, givenMyString.returnMyeowString()) <= 0;
    }






    bool operator>(const MyString& firstMyString, const MyString& secondMyString) {
        return strcmp(firstMyString.returnMyeowString(), secondMyString.returnMyeowString()) > 0;
    }







    bool operator>(const MyString& givenMyString, const char* givenCString) {
        return strcmp(givenMyString.returnMyeowString(), givenCString) > 0;
    }







    bool operator>(const char* givenCString, const MyString& givenMyString) {
        return strcmp(givenCString, givenMyString.returnMyeowString()) > 0;
    }







    bool operator>=(const MyString& firstMyString, const MyString& secondMyString) {
        return strcmp(firstMyString.returnMyeowString(), secondMyString.returnMyeowString()) >= 0;
    }







    bool operator>=(const MyString& givenMyString, const char* givenCString) {
        return strcmp(givenMyString.returnMyeowString(), givenCString) >= 0;
    }







    bool operator>=(const char* givenCString, const MyString& givenMyString) {
        return strcmp(givenCString, givenMyString.returnMyeowString()) >= 0;
    }







    bool operator==(const MyString& firstMyString, const MyString& secondMyString) {
        return strcmp(firstMyString.returnMyeowString(), secondMyString.returnMyeowString()) == 0;
    }







    bool operator==(const MyString& givenMyString, const char* givenCString) {
        return strcmp(givenMyString.returnMyeowString(), givenCString) == 0;
    }







    bool operator==(const char* givenCString, const MyString& givenMyString) {
        return strcmp(givenCString, givenMyString.returnMyeowString()) == 0;
    }






    bool operator!=(const MyString& firstMyString, const MyString& secondMyString) {
        return strcmp(firstMyString.returnMyeowString(), secondMyString.returnMyeowString()) != 0;
    }






    bool operator!=(const MyString& givenMyString, const char* givenCString) {
        return strcmp(givenMyString.returnMyeowString(), givenCString) != 0;
    }






    bool operator!=(const char* givenCString, const MyString& givenMyString) {
        return strcmp(givenCString, givenMyString.returnMyeowString()) != 0;
    }







    std::ostream& operator<<(std::ostream& outPut, const MyString& givenMyString) {
        outPut << givenMyString.returnMyeowString();
        return outPut;
    }

    std::istream& operator>>(std::istream& in, MyString& target)
    {
        while (isspace(in.peek())){
            in.ignore();
        }

    char temp[MyString::MAX_INPUT_SIZE + 1];
    in.getline(temp, MyString::MAX_INPUT_SIZE, ' ');
    target = MyString(temp);

        return in;
    }

}


