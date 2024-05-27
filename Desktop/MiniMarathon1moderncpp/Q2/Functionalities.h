#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include<iostream>
#include<vector>
#include "Device.h"
#include "VectorEmptyException.h"
#include "IDNotFoundException.h"
#include "InvalidDataException.h"

using Container = std::vector<Device*>;

/* 
    create 5 instances of device on heap memory
*/
void CreateObjects(Container &data);

/* 
    Function to find and return device id of all instances in a containerwhich return battery drain factor value below 0.4
*/
std::string FindIDofBatteryDrain(Container &data);

/* 
    check if all device type are same in all container!!
*/
bool CheckIfAllTypeAreSame(Container &data);

/* 
    function to display lowest and highest size in bytes amongdt instances whose release quarter is either Q1 or Q4.
 */
void DisplayLowestAndHighest(Container &data);

/* 
    FUNCTION TO find versionnumber of device driver whose device id matches with given parameter.
*/
std::string FindVersionNumber(Container &data, std::string id);

/* 
    delete all instances
*/

void DeleteObject(Container &data);


#endif // FUNCTIONALITIES_H
