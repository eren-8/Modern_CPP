#include "Functionalities.h"

int main(){
    try{
        Container data;
        CreateObjects(data);

        // std::cout<<"Function to display bonuses is: "<<"\n";
        // DisplayCalculateBonus(data);

        // std::cout<<"If all employees have salary above 50000 \n";
        // if(DisplayIfEmphaveSalAbove50K(data)){
        //     std::cout<<"True\n";
        // }
        // else{
        //     std::cout<<"False\n";
        // }

        // std::cout<<"Function to find attribute of department that have grade as given below.\n";
        // Display(data,FTEGrade::A);
        
        // std::cout<<"the project name of given id is: ";
        // std::string projname = FindAndReturnProjectName(data,"1");
        // std::cout<<projname<<"\n";
        for(auto obj : data){
            std::cout<<*obj<<"\n";
        }


        DeleteObjects(data);
    }
    catch(ListEmptyException &ex){
        std::cout<<ex.what()<<"\n";
    }
    catch(IDNotFoundException &ex){
        std::cout<<ex.what()<<"\n";
    }
}