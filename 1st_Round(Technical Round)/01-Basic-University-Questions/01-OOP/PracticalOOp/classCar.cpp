#include<iostream>
using namespace std;
class CAR{
    public:
    // Attributes variable
        string manufacturer = "Honda";
        // string modelNo "Civic";
        string color = "black";
        string tryerCompanyName = "SLM";
        string interiorDashboardColor = "light brown";
        string MadeByWhichCountry = "Japan";
        bool IsImported = true;
        int millage = 15;
        bool IsSadanCar;
        bool IsConvertableCar;
        bool IsDiselCar;
        bool IsLuxaryCar;
        bool IsElectricCar;
        bool IsSuvCar;
        bool IsWagonCar;
        bool IsTowTruckCar;
        int horsePower = 20;
    
    //Methods Working
    void start(){
        bool IsKeyPluggedIn = true;
        cout<<"Move the key towards clockWise";
    }
    void end(){
        cout<<"end";
    }
    void moveForward(){
        cout<<"Moving";
    }
    void moveBackward(){
        cout<<"moving back";
    }
    private:
        string RegistrationNumber = "Sindh LS201";
    protected:
        bool brandnew = true;
};
class HondaCivic{
    public:
        string modelName = "Honda civic";
        string price = "10,000";
        int VechicleId = 222222;
    private:
    int RegistrationNumber = 123456;
    protected:
};
int main(){
    // The values of object1 and object2 will be different bcz they contain their own memory.
    HondaCivic object1;
    object1.VechicleId = 1234;
    HondaCivic object2;
    cout<<object1.VechicleId<<endl;
    cout<<object2.VechicleId<<endl;
    // When we try to access the private and protected access specifer we get errors by compiler
    // cout<<object1.RegistrationNumber;
}