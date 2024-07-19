#include "DeviceDriver.h"

DeviceDriver::DeviceDriver(std::string versionnumber, DeviceDriverType type, float sizeinbyte)
    :_version_number{versionnumber}, _type{type}, _size_in_byte{sizeinbyte}
{
}
std::ostream &operator<<(std::ostream &os, const DeviceDriver &rhs) {
    os << "_version_number: " << rhs._version_number
       << " _type: ";
       if(static_cast<int>(rhs._type)==0){
        os<<"Q1";
       }
       else if(static_cast<int>(rhs._type)==1){
        os<<"Q2";
       }
       else if(static_cast<int>(rhs._type)==2){
        os<<"Q3";
       }
       else if(static_cast<int>(rhs._type)==3){
        os<<"Q4";
       }
       os<< " _size_in_byte: " << rhs._size_in_byte;
    return os;
}
