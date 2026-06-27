#include<iostream>
#include <SQLiteCpp/SQLiteCpp.h>

using namespace std;
class Book{
private:
public:
};
class User{
    private:
    public:
};
class Author{
    private:
    public:
};
class Dashboard{
    private:
    public:
    
};
int main(){
    for(int i = 1; i < 5;i++){
        cout<<"---------------------------------------------------------------\n";
    }
    cout<<"--------<<<< Welcome to libraryManagementSystem >>>>-----------\n";
    for(int i = 1; i < 5;i++){
        cout<<"---------------------------------------------------------------\n";
    }
    int dashboardinput = 0;
    cout<<"Press 1 to 'Login as Admin' \n";
    cout<<"Press 2 to 'Login as User' \n";
    cout<<"Press 3 to 'Exit Program' \n";
    cin>>dashboardinput;
    while (condition) {
        if(dashboardinput == 1 || dashboardinput == 2 || dashboardinput == 3){
            if(dashboardinput == 1){
                cout<<"Welcome admin";
            }else if(dashboardinput == 2){
                cout<<"Welcome user";
            }else{
                cout<<"Exit program";
            }
        }else{
           cout<<"\nPress any number 1, 2, 3 to choose option";
           cin>>dashboardinput;
        }
    }
 
        
    


}