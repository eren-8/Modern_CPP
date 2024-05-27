#ifndef DEVICE_H
#define DEVICE_H

#include <iostream>
#include "DeviceType.h"
#include "DeviceDriver.h"

class Device 
{
private:
    std::string _device_id {"0"};
    DeviceType _type {DeviceType::ACCESSORY};
    int _device_battery_level {1};
    DeviceDriver *_device_driver {nullptr};

public:
    Device() = default; // Default constructor
    Device(const Device&) = default; // Copy constructor
    Device& operator=(const Device&) = delete; // Copy assignment operator
    Device(Device&&) = delete; // Move constructor
    Device& operator=(Device&&) = delete; // Move assignment operator
    ~Device() = default; // Destructor

    Device(std::string id, DeviceType type, int batterylevel, DeviceDriver *driver);

    float FindBatteryDrainFactor();

    std::string deviceId() const { return _device_id; }

    DeviceType type() const { return _type; }
    void setType(const DeviceType &type) { _type = type; }

    int deviceBatteryLevel() const { return _device_battery_level; }
    void setDeviceBatteryLevel(int device_battery_level) { _device_battery_level = device_battery_level; }

    DeviceDriver *deviceDriver() const { return _device_driver; }
    void setDeviceDriver(DeviceDriver *device_driver) { _device_driver = device_driver; }

    friend std::ostream &operator<<(std::ostream &os, const Device &rhs);
};

#endif // DEVICE_H
