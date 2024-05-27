#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "Order.h"
#include<vector>
#include<iostream>
#include "ArrayEmptyException.h"
#include "IDNotFoundException.h"
#include "InputInvalid.h"

using Container = std::vector<Order*>;

/* 
    create 5 objects in the heap of order class and store their addresses in a list container 
*/

void CreateObjects(Container &data);

/* 
    Function to find and return the id of order whose discount amount is the lowest. If there are multiple lowest values, 
    consider the first lowest found from the start of the data conatiner.
*/
std::string FindIdOfLowestDiscountAmount(const Container &data);

/* 
    Function to find and return the type of the order whose id is passed as an argument.
*/
std::string FindAndReturnTypeOfOrderBasedOnID(const Container &data, const std::string id);

/* 
    Funciton to find and return average value of all orders in the container.
*/
float FindAverage(const Container &data);

/* 
    Function to find last N instances in the container whose n is passed as a parameter to the function.
*/
Container FindLastNInstances(Container &data, int N);

/* 
    Function to delete all the instances created using heap memory
*/

void DeleteObjects(Container &data);

#endif // FUNCTIONALITIES_H
