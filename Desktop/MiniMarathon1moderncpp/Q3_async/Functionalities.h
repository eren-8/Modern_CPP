#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "FullTimeEmployee.h"
#include <list>
#include<iostream>
#include<variant>
#include "ListEmptyException.h"
#include "IDNotFoundException.h"

using Container = std::list<FullTimeEmployee*>;
using VType = std::variant<FullTimeEmployee,Employee>;
using VTypeContainer = std::list<VType>;
/* 
    function to create 3 objects on heap of FTE class and store their addresses in a list
*/
void CreateObjects(VTypeContainer &data);

/* 
    Function to display result by invokiing calculatebonus function.
*/
void DisplayCalculateBonus(Container &data);

/* 
    function to display true or false if all employees have salary above 50000 or not.
*/
bool DisplayIfEmphaveSalAbove50K(Container &data);

/* 
    function to find and display the attributes of dept instance of all FTE instances in the container whose grade matches 
    as passed in parameter
*/
void Display(Container &data, FTEGrade grade);

/* 
    function to find and return project name of employee whose id is passed as an argument .
*/
std::string FindAndReturnProjectName(Container &data, std::string id);

/* 
    function to delete all memory allocations
*/
void DeleteObjects(Container &data);

#endif // FUNCTIONALITIES_H

