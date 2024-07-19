#include "FullTimeEmployee.h"

FullTimeEmployee::FullTimeEmployee(std::string name, std::string id, float salary, Department dept,std::string project_name, std::string employee_location, FTEGrade grade, int bonus_percent)
    :Employee(name,id,salary,dept),_project_name{project_name}, _employee_location{employee_location}, _grade{grade}, _bonus_percent{bonus_percent}
{
}

float FullTimeEmployee::CalculateBonus()
{
    float temp = 0.0f;
    if(_grade==FTEGrade::A){
         temp = _bonus_percent * salary();
    }
    else if(_grade==FTEGrade::B){
         temp = _bonus_percent * salary()/2.0;
    }
    else if(_grade==FTEGrade::C){
         temp = _bonus_percent * salary()/4.0;
    }
    return temp;
}

std::ostream &operator<<(std::ostream &os, const FullTimeEmployee &rhs) {
    os << static_cast<const Employee &>(rhs)
       << " _project_name: " << rhs._project_name
       << " _employee_location: " << rhs._employee_location
       << " _grade: ";
        if(static_cast<int>(rhs._grade)==0){
          os<<"A";
        }
        else if(static_cast<int>(rhs._grade)==1){
          os<<"B";
        }
        else if(static_cast<int>(rhs._grade)==2){
          os<<"C";
        }
       os<< " _bonus_percent: " << rhs._bonus_percent;
    return os;
}
