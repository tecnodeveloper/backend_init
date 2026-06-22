#include<iostream>
using namespace std;
class Bank{
    private:
        double balance;
    public:
    Bank(int IntialBalance){
        balance = IntialBalance;
    }
    void deposit(){
        int depositMoney = 0;
        cout<<"Enter the money for deposit \n";
        cin>>depositMoney;
        if(depositMoney > 0){
            balance = balance + depositMoney;
            cout<<depositMoney<<" money is succussfully deposited. Your current balance is "<<balance<<endl;
        }else{
            cout<<"Please enter the correct number to deposit "<<" is not correct number"<<endl;
        }
    }
    void withdraw(){
        int withdrawMoney = 0;
        cout<<"Enter the money for withdraw"<<endl;
        cin>>withdrawMoney;
        if(withdrawMoney < balance){
            balance = balance - withdrawMoney;
            cout<<withdrawMoney<<" money is succussfully withdraw. Your current balance is "<<balance<<endl;
        }else{
            cout<<"Please enter the correct money for withdraw "<<withdrawMoney<<" is not correct number"<<endl;
        }
    }
    void display(){
        cout<<"Your current balance is "<<balance<<endl;
    }
};
int main(){
    Bank account(1000);
    account.display();
    account.deposit();
    account.withdraw();
}