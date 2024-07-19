#ifndef DEVICEDRIVER_H
#define DEVICEDRIVER_H

#include <iostream>
#include "DeviceDriverType.h"

class DeviceDriver 
{
private:
    std::string _version_number {"0"};
    DeviceDriverType _type {DeviceDriverType::Q1};
    float _size_in_byte {0.0f};

public:
    DeviceDriver() = default; // Default constructor
    DeviceDriver(const DeviceDriver&) = default; // Copy constructor
    DeviceDriver& operator=(const DeviceDriver&) = delete; // Copy assignment operator
    DeviceDriver(DeviceDriver&&) = delete; // Move constructor
    DeviceDriver& operator=(DeviceDriver&&) = delete; // Move assignment operator
    ~DeviceDriver() = default; // Destructor

    DeviceDriver(std::string versionnumber,DeviceDriverType type, float sizeinbyte);

    std::string versionNumber() const { return _version_number; }

    DeviceDriverType type() const { return _type; }
    void setType(const DeviceDriverType &type) { _type = type; }

    float sizeInByte() const { return _size_in_byte; }
    void setSizeInByte(float size_in_byte) { _size_in_byte = size_in_byte; }

    friend std::ostream &operator<<(std::ostream &os, const DeviceDriver &rhs);
};

#endif // DEVICEDRIVER_H
