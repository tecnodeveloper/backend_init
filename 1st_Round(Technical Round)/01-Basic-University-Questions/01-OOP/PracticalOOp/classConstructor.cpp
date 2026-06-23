#include<iostream>
using namespace std;
class Person{
    private:
        string name;
        int age;
        int rollNo;
    public:
        Person(string name, int age, int rollNo )
        {
            this->name = name;
            this->age = age;
            this->rollNo = rollNo;
            cout<<"Constructor is called and it's used to intialize the values of object"<<endl;
        }
        void display(){
            cout<<"Name "<<name<<endl;
            cout<<"Age "<<age<<endl;
            cout<<"Roll No "<<rollNo<<endl;
        }
        ~Person(){
            cout<<"Destructor is called and memory is cleaned"<<endl;
        }
};
int main(){
    Person Zain("Zain Ali",22,230201330);
    Zain.display();
}