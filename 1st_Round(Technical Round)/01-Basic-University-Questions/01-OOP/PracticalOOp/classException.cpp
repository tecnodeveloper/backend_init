#include<iostream>
using namespace std;
class ExceptionClass{
    private:
        int number1;
        int number2;
    public:
        ExceptionClass(int number1,int number2){
            this->number1 = number1;
            this->number2 = number2;
        }

        void division(){
            // We don't write or handle error in try block we just throw the error to catch block`
        try{
    
            if(number2 == 0){
                throw number2;
            }
            else{
                cout<<"The division of number is "<<number1/number2<<endl;
            }
        }
        catch(int number2){
          cout<<"Can't divide by "<<number2<<endl;
          cout<<"End of program......"<<endl;
        }
    }
};
int main(){
    int number1,number2;
    cout<<"Enter first number: ";
    cin>>number1;
    cout<<"Enter second number for division";
    cin>>number2;

    ExceptionClass objectException(number1,number2);
    objectException.division();
}