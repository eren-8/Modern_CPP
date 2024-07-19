
#ifndef IDNOTFOUNDEXCEPTION_H
#define IDNOTFOUNDEXCEPTION_H

#include <stdexcept>
#include <string>
#include <cstring>
class IDNotFoundException : public std::exception
{
    std::string _msg;

public:
    IDNotFoundException() = delete;

    IDNotFoundException(const IDNotFoundException &) = delete; // disabled copy constructor

    IDNotFoundException(IDNotFoundException &&) = delete; // disabled move constructor brand new in C++11

    IDNotFoundException &operator=(const IDNotFoundException &) = delete; // disabled assignment operator
    IDNotFoundException &operator=(IDNotFoundException &&) = delete;      // disabled assignment move operator brand new in C++11

    ~IDNotFoundException() = default;
    IDNotFoundException(std::string msg) : _msg(msg)
    {
    }
    virtual const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override
    {
        return _msg.c_str();
    }

    
};

#endif // IDNOTFOUNDEXCEPTION_H
