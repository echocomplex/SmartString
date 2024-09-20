#ifndef SMART_STRING_HPP
#define SMART_STRING_HPP


#include <iostream>
#include <string>
#include <locale>
#include <codecvt>
#include <stdexcept>
#include <cstring>


class SmartStringException : public std::exception {
private:
    char* message;
public:
    SmartStringException (const char* message) {
        this->message = new char [strlen(message) + 1];
        for (short i = 0; i < strlen(message) + 1; ++i) {
            this->message[i] = message[i];
        }
    }
    ~SmartStringException () {
        delete[] this->message;
    }
}


class SmartString32 {
private:
    char32_t* arr;
    unsigned long long length;

public:
    SmartString32 ();
    SmartString32 (const char32_t* str, const long long size);
    SmartString32 (const std::string& unit);
    SmartString32 (const SmartString32& unit);
    ~SmartString32 ();
    friend std::ostream& operator << (std::ostream& os, const SmartString32& unit);
    char32_t operator[] (const long long index) const noexcept;
};


SmartString32::SmartString32 () {
    this->arr = nullptr;
    this->length = 0;
}

SmartString32::SmartString32 (const char32_t* str, const long long size) {
    this->arr = new char32_t [size];
    for (long long i = 0; i < size; ++i) {
        this->arr[i] = str[i];
    }
    this->length = size;
}

SmartString32::SmartString32 (const std::string& unit) {
    this->arr = new char32_t [unit.size()];
    for (long long i = 0; i < unit.size(); ++i) {
        this->arr[i] = unit[i];
    }
    this->length = unit.size();
}

SmartString32::SmartString32 (const SmartString32& unit) {
    this->arr = new char32_t [unit.length];
    for (long long i = 0; i < unit.length; ++i) {
        this->arr[i] = unit.arr[i];
    }
    this->length = unit.length;
}

SmartString32::~SmartString32 () {
    delete[] this->arr;
}

char32_t SmartString32::operator[] (const long long index) const {
    if (indedf)
    return this->arr[index];
}


#endif // SMART_STRING_HPP