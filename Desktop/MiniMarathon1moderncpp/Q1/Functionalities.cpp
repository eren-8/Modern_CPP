#include "Functionalities.h"

void CreateObjects(Container &data)
{
    data.push_back(new Order("1",1000.0f, OrderType::COD, 300.0f));
    data.push_back(new Order("2",2000.0f, OrderType::COD, 400.0f));
    data.push_back(new Order("3",3000.0f, OrderType::COD, 500.0f));
    data.push_back(new Order("4",4000.0f, OrderType::COD, 600.0f));
    data.push_back(new Order("5",5001.0f, OrderType::COD, 700.0f));
}

std::string FindAndReturnTypeOfOrderBasedOnID(const Container &data, const std::string id)
{
    OrderType type;
    int flag=0;
    if(data.empty()){
        throw ArrayEmptyException("Container is empty!!");
    }
    for(int i=0;i<5;i++){
        if(id == data[i]->orderId()){
            type = data[i]->type();
            flag=1;
        }
    }
    if(flag==0){
        throw IDNotFoundException("ID not found!!");
    }
    if(type==OrderType::PAID){
        return "PAID";
    }
    else if(type==OrderType::COD){
        return "COD";
    }
    else if(type == OrderType::PROMOTION){
        return "PROMOTION";
    }
    else{
        throw InputInvalid("Invalid input");
    }
}

float FindAverage(const Container &data)
{
    float sum = 0.0f;
    if(data.empty()){
        throw ArrayEmptyException("Container is empty!!");
    }
    for(int i=0;i<5;i++){
        sum += data[i]->value();
    }
    return static_cast<float>(sum/data.size());
}

Container FindLastNInstances(Container &data, int N)
{
    Container lastNInstance;
    int count=0;
    if(data.empty()){
        throw ArrayEmptyException("Container is empty!!");
    }
    if(N<0 || N>data.size()){
        throw "VALUE OF N IS INVALID!!";
    }
    for(Container::reverse_iterator itr=data.rbegin();itr!=data.rend();++itr){
        if(count == N){
            break;
        }
        else{
            lastNInstance.push_back(*itr);
            count++;
        }
    }
    return lastNInstance;
}

void DeleteObjects(Container &data)
{
    if(data.empty()){
        throw ArrayEmptyException("Container is empty!!");
    }
    for(Order* obj:data){
        if(obj){
            delete obj;
        }
    }
}

std::string FindIdOfLowestDiscountAmount(const Container &data)
{
    std::string lowestdiscount_id=data[0]->orderId();
    float disc_amount = data[0]->discount();
    if(data.empty()){
        throw ArrayEmptyException("Container is empty!!");
    }
    for(Order* obj:data){
        if(obj->discount()<disc_amount){
            disc_amount = obj->discount();
            lowestdiscount_id = obj->orderId();
        }
    }
    return  lowestdiscount_id;
}
