#ifndef INPUTINVALID_H
#define INPUTINVALID_H


#include <stdexcept>
#include <string>
#include <cstring>
class InputInvalid : public std::exception
{
    std::string _msg;

public:
    InputInvalid() = delete;

    InputInvalid(const InputInvalid &) = delete; // disabled copy constructor

    InputInvalid(InputInvalid &&) = delete; // disabled move constructor brand new in C++11

    InputInvalid &operator=(const InputInvalid &) = delete; // disabled assignment operator
    InputInvalid &operator=(InputInvalid &&) = delete;      // disabled assignment move operator brand new in C++11

    ~InputInvalid() = default;
    InputInvalid(std::string msg) : _msg(msg)
    {
    }
    virtual const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override
    {
        return _msg.c_str();
    }

    
};

#endif // INPUTINVALID_H
