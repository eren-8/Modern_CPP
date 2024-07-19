#include "Device.h"

Device::Device(std::string id, DeviceType type, int batterylevel, DeviceDriver *driver)
    :_device_id{id}, _type{type}, _device_battery_level{batterylevel}, _device_driver{driver}
{
}

float Device::FindBatteryDrainFactor()
{
    float batterydrain;
    if(_type==DeviceType::ACCESSORY || _type==DeviceType::INFOTAINMENT){
        batterydrain = 0.25;
    }
    else if(_type==DeviceType::SAFETY){
        if(_device_battery_level>50){
            batterydrain = 0.5;
        }
        else{
            batterydrain = 0.4;
        }
    }
    return batterydrain;
}

std::ostream &operator<<(std::ostream &os, const Device &rhs) {
    os << "_device_id: " << rhs._device_id
       << " _type: ";
        if(static_cast<int>(rhs._type)==0){
            os<<"INFOTAINMENT";
        }
        else if(static_cast<int>(rhs._type)==1){
            os<<"ACCESSORY";
        }
        else if(static_cast<int>(rhs._type)==2){
            os<<"SAFETY";
        }
       os<< " _device_battery_level: " << rhs._device_battery_level
       << " _device_driver: " << rhs._device_driver;
    return os;
}
