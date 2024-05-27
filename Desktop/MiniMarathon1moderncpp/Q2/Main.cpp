#include "Functionalities.h"

int main(){
    try{
        Container data;
        CreateObjects(data);
        std::string answer = FindIDofBatteryDrain(data);
        std::cout<<"ID of number which has battery drain less than 0.4 is: "<<answer<<"\n";

        bool checktype = CheckIfAllTypeAreSame(data);
        if(checktype){
            std::cout<<"YES THE TYPE OF ALL DEVICE INSTANCES ARE SAME!";
        }
        else{
            std::cout<<"NO THE TYPE OF ALL DEVICE INSTANCES ARE SAME!";
        }

        DisplayLowestAndHighest(data);

        std::string versionnum = FindVersionNumber(data,"7");
        std::cout<<"THE VERSION_NUMBER of devicedriver is: "<<versionnum<<"\n";

        DeleteObject(data);
    }
    catch(VectorEmptyException &ex){
        std::cout<<ex.what()<<"\n";
    }
    catch(IDNotFoundException &ex){
        std::cout<<ex.what()<<"\n";
    }
    catch(InvalidDataException &ex){
        std::cout<<ex.what()<<"\n";
    }
}