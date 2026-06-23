#include<iostream>
using namespace std;
class SumNumbers{
    private:
    public:
        SumNumbers(int number1,int number2){
            cout<<"Sum of numbers "<<number1 + number2<<endl;
        }
        SumNumbers(int number1, int number2, int number3){
            cout<<"Sum of numbers are "<<number1 + number2 + number3<<endl;
        }
};
int main(){
    SumNumbers object1(2,3);
    SumNumbers object2(2,3,4);
}