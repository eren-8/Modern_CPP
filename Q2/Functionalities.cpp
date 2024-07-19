#include "Functionalities.h"

void CreateObjects(Container &data)
{
    data.push_back(new Device(
        "1",DeviceType::SAFETY,80,
        new DeviceDriver("123",DeviceDriverType::Q1,32.0f)
    ));
    data.push_back(new Device(
        "2",DeviceType::INFOTAINMENT,70,
        new DeviceDriver("1234",DeviceDriverType::Q2,55.0f)
    ));
    data.push_back(new Device(
        "3",DeviceType::SAFETY,60,
        new DeviceDriver("124",DeviceDriverType::Q3,321.0f)
    ));
    data.push_back(new Device(
        "4",DeviceType::ACCESSORY,80,
        new DeviceDriver("222",DeviceDriverType::Q4,532.0f)
    ));
    data.push_back(new Device(
        "5",DeviceType::SAFETY,100,
        new DeviceDriver("111",DeviceDriverType::Q1,323.0f)
    ));
}

std::string FindIDofBatteryDrain(Container &data)
{
    std::string id="";
    if(data.empty()){
        throw VectorEmptyException("Data is empty!!");
    }
    for(Device* obj:data){
        if(obj->FindBatteryDrainFactor()<0.4){
            id = obj->deviceId();
        }
    }
    if(id==""){
        throw IDNotFoundException("NO ID EXISTS FOR BATTERY DRAIN FACTOR BELOW 0.4");
    }
    return id;
}

bool CheckIfAllTypeAreSame(Container &data)
{
    int count=0;
    DeviceType type = data[0]->type();
    if(data.empty()){
        throw VectorEmptyException("Data is empty!!");
    }
    for(Device* obj:data){
        if(obj->type() == type){
            count++;
        }
    }
    if(count==data.size()){
        return true;
    }
    else{
        return false;
    }
}

void DisplayLowestAndHighest(Container &data)
{
    float minimum=1000000;
    float maximum=0;
    if(data.empty()){
        throw VectorEmptyException("Data is empty!!");
    }
    for(Device* obj:data){
        if((obj->deviceDriver()->type()==DeviceDriverType::Q1) || (obj->deviceDriver()->type()==DeviceDriverType::Q4)){
            if(obj->deviceDriver()->sizeInByte()<minimum){
                minimum = obj->deviceDriver()->sizeInByte();
            }
            if(obj->deviceDriver()->sizeInByte()>maximum){
                maximum = obj->deviceDriver()->sizeInByte();
            }
        }
    }
    if(minimum==1000000 || maximum==0){
        throw InvalidDataException("There is no instance where q1 or q4 exists!!");
    }
    std::cout<<"LOWEST VALUE OF SIZE IN BYTE IS: "<<minimum<<"\n";
    std::cout<<"HIGHEST VALUE OF SIZE IN BYTE IS: "<<maximum<<"\n";
}

std::string FindVersionNumber(Container &data, std::string id)
{
    std::string number="";
    if(data.empty()){
        throw VectorEmptyException("Data is empty!!");
    }
    for(Device* obj:data){
        if(obj->deviceId()==id){
            number = obj->deviceDriver()->versionNumber();
        }
    }
    if(number==""){
        throw InvalidDataException("id does not exist in all the instances!!");
    }
    return number;
}

void DeleteObject(Container &data)
{
    for(Device* obj:data){
        if(obj){
            if(obj->deviceDriver()){
                delete obj->deviceDriver();
            }
            delete obj;
        }

    }
}
