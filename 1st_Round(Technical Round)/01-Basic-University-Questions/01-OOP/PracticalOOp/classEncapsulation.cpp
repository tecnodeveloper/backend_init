#include<iostream>
using namespace std;
class Employee{
	private:
		int salary;
	public:
		Employee(int IntialSalary){
			salary = IntialSalary;
		}
		void getSalary(){
			cout<<"Your salary is "<<salary<<endl;
		}
};
int main(){
    Employee Salman(2000);
    Salman.getSalary();
//    Salman.salary; you cann't change directly salary this is encapsulation
}