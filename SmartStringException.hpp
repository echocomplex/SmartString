#ifndef SMART_STRING_EXCEPTION
#define SMART_STRING_EXCEPTION



#include <iostream>
#include <stdexcept>
#include <string>



class SmartStringException : public std::exception {
private:
    char* message;
public:
    SmartStringException (const char* message) noexcept {
        this->message = new char [strlen(message) + 1];
        for (short i = 0; i < strlen(message) + 1; ++i) {
            this->message[i] = message[i];
        }
    }
    ~SmartStringException () noexcept {
        delete[] this->message;
    }
};



#endif // SMART_STRING_EXCEPTION