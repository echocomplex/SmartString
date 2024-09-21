#ifndef SMART_STRING_HPP
#define SMART_STRING_HPP



#include <iostream>
#include <string>
#include <locale>
#include <codecvt>
#include <stdexcept>
#include <cstring>
#include <fstream>



class SmartString32 {
private:
    char32_t* arr;
    unsigned long long length;

public:
    SmartString32 () noexcept;
    SmartString32 (const char32_t* str, const long long size);
    SmartString32 (const std::string& unit);
    SmartString32 (const SmartString32& unit);
    ~SmartString32 ();
    friend std::ostream& operator << (std::ostream& os, const SmartString32& unit);
    friend std::ofstream& operator<<(std::ofstream& ofs, const SmartString32& str)
    friend std::ifstream& operator>>(std::ifstream& ifs, SmartString32& str) {
        ifs.read(reinterpret_cast<char*>(&str.character), sizeof(char32_t));
        return ifs;
    }
    char32_t operator[] (const long long index) const noexcept;
};



SmartString32::SmartString32 () noexcept {
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

SmartString32::~SmartString32 () noexcept {
    delete[] this->arr;
}

std::ofstream& operator<<(std::ofstream& ofs, const SmartString32& str) {
    ofs.write(reinterpret_cast<const char*>(&str.character), sizeof(char32_t));
    return ofs;
}

char32_t SmartString32::operator[] (const long long index) const noexcept {
    return this->arr[index];
}


#endif // SMART_STRING_HPP