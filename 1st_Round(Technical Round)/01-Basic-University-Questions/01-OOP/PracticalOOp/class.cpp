#include<iostream>
using namespace std;
class CAR{
    public:
        int carDetail(){
            bool sadan_Cars;
        }
        string color = "black";
        string tryerCompanyName = "SLM";
        string engineName = "";
        string interiorDashboardColor = "light brown";
        string MadeByWhichCountry = "Japan";
        bool IsImported = true;
        int millage = 15;


    private:
        string RegistrationNumber = "Sindh";
    protected:
        bool brandnew = true;
};
class HondaCivic{
    public:
        string modelName = "Honda civic";
        int price = 10,000;
    private:
    protected:
};
int main(){
    carDesign object1;
    object1.VechicleId = "1223";
    carDesign object2;
    cout<<object1.VechicleId<<endl;
    cout<<object2.VechicleId<<endl;
    // When we try to access the private and protected access specifer we get errors by compiler
    cou<<
}