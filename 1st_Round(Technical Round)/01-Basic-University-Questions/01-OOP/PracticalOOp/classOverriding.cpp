#include<iostream>
using namespace std;
class Car{
    public:
        void engine(){
            cout<<"Car must have engine or electric car or hybrid "<<endl;
        }
};
class civic : public Car{
    public:
    void engine(){
        cout<<"Honda civic has 2.0 turbo charged engine"<<endl;
    }

};
int main(){
    // There is engine function in parent class which is override by child class
    civic carCivic;
    carCivic.engine();
}