#include <iostream>
using namespace std;
class student{
    public:
        int rollNo;
        string Name;
        string ClassName;
    void studying(){
        cout<<"Student is studying";
    }
};
int main()
{
    student zain;
    student salman;
    zain.rollNo = 230201330;
    salman.rollNo = 12;
    zain.studying();
    return 0;
}