
#ifndef LISTEMPTYEXCEPTION_H
#define LISTEMPTYEXCEPTION_H

#include <stdexcept>
#include <string>
#include <cstring>
class ListEmptyException : public std::exception
{
    std::string _msg;

public:
    ListEmptyException() = delete;

    ListEmptyException(const ListEmptyException &) = delete; // disabled copy constructor

    ListEmptyException(ListEmptyException &&) = delete; // disabled move constructor brand new in C++11

    ListEmptyException &operator=(const ListEmptyException &) = delete; // disabled assignment operator
    ListEmptyException &operator=(ListEmptyException &&) = delete;      // disabled assignment move operator brand new in C++11

    ~ListEmptyException() = default;
    ListEmptyException(std::string msg) : _msg(msg)
    {
    }
    std::string what(){
        return _msg;
    }

    
};

#endif // LISTEMPTYEXCEPTION_H
