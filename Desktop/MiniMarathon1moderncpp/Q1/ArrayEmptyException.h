#ifndef ARRAYEMPTYEXCEPTION_H
#define ARRAYEMPTYEXCEPTION_H

#include <stdexcept>
#include <string>
#include <cstring>
class ArrayEmptyException : public std::exception
{
    std::string _msg;

public:
    ArrayEmptyException() = delete;

    ArrayEmptyException(const ArrayEmptyException &) = delete; // disabled copy constructor

    ArrayEmptyException(ArrayEmptyException &&) = delete; // disabled move constructor brand new in C++11

    ArrayEmptyException &operator=(const ArrayEmptyException &) = delete; // disabled assignment operator
    ArrayEmptyException &operator=(ArrayEmptyException &&) = delete;      // disabled assignment move operator brand new in C++11

    ~ArrayEmptyException() = default;
    ArrayEmptyException(std::string msg) : _msg(msg)
    {
    }
    virtual const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override
    {
        return _msg.c_str();
    }

    
};

#endif // ARRAYEMPTYEXCEPTION_H
