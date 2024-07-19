#include "Functionalities.h"

int main(){
    try{
        Container data;
        CreateObjects(data);

        std::string id = FindIdOfLowestDiscountAmount(data);
        std::cout<<"The ID of lowest discoutnamount is: "<<id<<"\n";
        
        std::string type = FindAndReturnTypeOfOrderBasedOnID(data,"3");
        std::cout<<"The type of give id is: "<<type<<"\n";
        
        float average = FindAverage(data);
        std::cout<<"the average of data is: "<<average<<"\n";
        
        Container lastNinstance=FindLastNInstances(data,3);
        for(int i=0;i<3;i++){
            std::cout<<*lastNinstance[i];
        }
        std::cout<<"\n";
        
        DeleteObjects(data);
    }
    catch(ArrayEmptyException &ex){
        std::cout<<ex.what()<<"\n";
    }
    catch(IDNotFoundException &ex){
        std::cout<<ex.what()<<"\n";
    }
    catch(InputInvalid &ex){
        std::cout<<ex.what()<<"\n";
    }
}

