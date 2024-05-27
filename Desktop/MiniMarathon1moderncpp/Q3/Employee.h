#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include "Department.h"

class Employee 
{
private:
    std::string _name {""};
    std::string _id {"0"};
    float _salary {0.0f};
    Department _department;

public:
    Employee() = default; // Default constructor
    Employee(const Employee&) = default; // Copy constructor
    Employee& operator=(const Employee&) = delete; // Copy assignment operator
    Employee(Employee&&) = delete; // Move constructor
    Employee& operator=(Employee&&) = delete; // Move assignment operator
    virtual ~Employee() = default; // Destructor

    Employee(std::string name, std::string id, float salary, Department dept);//parametrized constructor

    virtual float CalculateBonus()=0;//pure virtual function

    std::string name() const { return _name; }//getter
    void setName(const std::string &name) { _name = name; }//setter

    std::string id() const { return _id; }//getter

    float salary() const { return _salary; }//getter
    void setSalary(float salary) { _salary = salary; }//setter

    Department department() const { return _department; }//getter


    friend std::ostream &operator<<(std::ostream &os, const Employee &rhs);//output stream operator overload
};

#endif // EMPLOYEE_H
