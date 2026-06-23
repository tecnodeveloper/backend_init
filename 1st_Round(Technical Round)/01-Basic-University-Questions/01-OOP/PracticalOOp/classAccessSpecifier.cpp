#include<iostream>
using namespace std;
class Acess{
    public:
        int rollno = 12;
    private:
        int marks = 200;
    protected: 
        string studentName = "Zain"; 
};
class IsAcess : public Acess{
    public:
    void display(){
    cout<<"Can i access private part of Access class";
    // cout<<marks<<endl; No you can't access the private part of class you need to use friend function
    cout<<rollno<<endl;
    cout<<studentName<<endl;
    }
};
int main(){
    Acess object1;
    IsAcess object2;
    object2.display();
    // cout<<object1.rollno<<endl;
}