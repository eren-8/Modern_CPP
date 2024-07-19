#ifndef FULLTIMEEMPLOYEE_H
#define FULLTIMEEMPLOYEE_H

#include <iostream>
#include "Employee.h"
#include "FTEGrade.h"

class FullTimeEmployee :public Employee
{
private:
    std::string _project_name {""};
    std::string _employee_location {""};
    FTEGrade _grade {FTEGrade::B};
    int _bonus_percent {1};

public:
    FullTimeEmployee() = default; // Default constructor
    FullTimeEmployee(const FullTimeEmployee&) = default; // Copy constructor
    FullTimeEmployee& operator=(const FullTimeEmployee&) = delete; // Copy assignment operator
    FullTimeEmployee(FullTimeEmployee&&) = delete; // Move constructor
    FullTimeEmployee& operator=(FullTimeEmployee&&) = delete; // Move assignment operator
    ~FullTimeEmployee() = default; // Destructor

    //parametrized constructor
    FullTimeEmployee(std::string name, std::string id, float salary, Department dept,std::string project_name, std::string employee_location, FTEGrade grade, int bonus_percent);

    //pure virtual function overriden in child class
    float CalculateBonus() override;

    std::string projectName() const { return _project_name; }//getter
    void setProjectName(const std::string &project_name) { _project_name = project_name; }//setter

    std::string employeeLocation() const { return _employee_location; }//getter
    void setEmployeeLocation(const std::string &employee_location) { _employee_location = employee_location; }//setter

    FTEGrade grade() const { return _grade; }//getter
    void setGrade(const FTEGrade &grade) { _grade = grade; }//setter

    int bonusPercent() const { return _bonus_percent; }//getter
    void setBonusPercent(int bonus_percent) { _bonus_percent = bonus_percent; }//setter

    friend std::ostream &operator<<(std::ostream &os, const FullTimeEmployee &rhs);//output stream operator overload
    
};

#endif // FULLTIMEEMPLOYEE_H
