#include<iostream>
using namespace std;
class addValue{
	private:
		int number1;
		int number2;
	public:
	addValue(int value1, int value2){
		number1 = value1;
		number2 = value2;
	}
	void sum(int number1, int number2){
		cout<<"Integer Sum function call "<<endl;
		cout<<"The sum of value is "<<number1 + number2<<endl;
	}
	void sum(double number1, double number2){
		cout<<"Float sum function call "<<endl;
		cout<<"The sum value is "<<number1 + number2<<endl;
	}
};
int main(){
	addValue adding(2,2);
	adding.sum(3.212 , 3.112);
//	adding.sum(12,2.12321); if we send one parameter as integer and other float then float value is truncated so we use function overloading A function can exist in multiple form.
}