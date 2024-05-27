#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <iostream>

class Department 
{
private:
    std::string _id {"0"};
    int _size {0};
    static int totalemp;

public:
    Department() = default; // Default constructor
    Department(const Department&) = default; // Copy constructor
    Department& operator=(const Department&) = delete; // Copy assignment operator
    Department(Department&&) = delete; // Move constructor
    Department& operator=(Department&&) = delete; // Move assignment operator
    ~Department() = default; // Destructor

    Department(std::string id);//parametrized constructor

    std::string id() const { return _id; } //getter

    int size() const { return _size; } //setter

    friend std::ostream &operator<<(std::ostream &os, const Department &rhs); //output stream overload
};

#endif // DEPARTMENT_H
