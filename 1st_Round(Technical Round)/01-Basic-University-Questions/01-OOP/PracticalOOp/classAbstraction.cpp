#include<iostream>
using namespace std;
class CoeffeeMachine{
	private:
		void boilwater(){
			cout<<"1st step boil water";
		}
		void brew(){
			cout<<"2nd step add brew to boul water";
		}
		void pour(){
			cout<<"3rd step add sugar to boul water";
		}
	public:
		void makeCoffeeCup(){
			cout<<"I'm starting making coffee"<<endl;
			boilwater();
			brew();
			pour();
		}
		
};
int main(){
	CoeffeeMachine cupObj;
//	So we hide complex functionality in private access specifier user can see easy functionality
	cupObj.makeCoffeeCup();
}