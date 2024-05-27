#include "Functionalities.h"

void CreateObjects(VTypeContainer &data)
{
    data.emplace_back(FullTimeEmployee("tanmay","1",60000.0f,Department("10"),
        "embedded","pune",FTEGrade::A,10
    ));
    data.emplace_back(FullTimeEmployee("john","2",65000.0f,Department("11"),
        "embedded","pune",FTEGrade::B,7
    ));
    data.emplace_back(Employee())   
}

void DisplayCalculateBonus(VTypeContainer &data)
{
    if(data.empty()){
        throw ListEmptyException("DATA is empty!!\n");
    }
    for(FullTimeEmployee* obj:data){
        std::cout<<"Bonus amount is: "<<obj->CalculateBonus()<<"\n";
    }
}

bool DisplayIfEmphaveSalAbove50K(Container &data)
{
    if(data.empty()){
        throw ListEmptyException("DATA is empty!!\n");
    }
    for(FullTimeEmployee* obj:data){
        if(obj->salary()<50000){
            return false;
        }
    }
    return true;
}

void Display(Container &data, FTEGrade grade)
{
    if(data.empty()){
        throw ListEmptyException("DATA is empty!!\n");
    }
    for(FullTimeEmployee *obj:data){
        
        if(obj && obj->grade()==grade){
            std::cout<<obj->department()<<"\n";
        }
    }
}

std::string FindAndReturnProjectName(Container &data, std::string id)
{
    if(data.empty()){
        throw ListEmptyException("DATA is empty!!\n");
    }
    std::string projname="";
    for(FullTimeEmployee *obj:data){
        if(obj->id()==id){
            projname = obj->projectName();
        }
    }
    if(projname==""){
        throw IDNotFoundException("ID is invalid or cannot be found!!");
    }
    return projname;
}

void DeleteObjects(Container &data)
{
    for(FullTimeEmployee* obj:data){
        if(obj){
            delete obj;
        }
    }
}
