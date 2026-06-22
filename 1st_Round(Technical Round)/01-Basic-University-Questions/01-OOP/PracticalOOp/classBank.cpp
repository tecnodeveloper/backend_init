#include<iostream>
using namespace std;
class Bank{
    public:
        double balance;
    void deposit(){
        int money = 0;
        cout<<"Enter the money for deposit \n";
        cin>>depositMoney;
        if(depositMoney > 0){
            cout<<"Your money is succussfully deposit "<<depositMoney<<endl;
            balance = depositMoney;
        }else{
            cout<<"Please enter the correct number to deposit "<<depositMoney<<endl;
        }
    }
    void withdraw(){
        int withdrawMoney = 0;
        cout<<"Enter the money for withdraw"<<endl;
        cin>>withdrawMoney;
        if(withdrawMoney < balance){
            cout<<"You have succussfully withdraw money "<<withdraw<<endl;
            balance = balance - withdrawMoney;
        }else{
            cout<<"Please enter the correct money for withdraw "<<withdrawMoney<<endl;
        }
    }
    void display(){
        cout<<"Your current balance is "<<balance<<endl;
    }
};
int main(){

}