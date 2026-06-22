#include<iostream>
using namespace std;
class Animal{
	private:
	public:
		void Sound(){
			cout<<"Animal can make noises"<<endl;
		}
		void eat(){
			cout<<"Animal can eat food"<<endl;
		}
		void walk(){
			cout<<"Animal can walk"<<endl;
		}
};
class Dog : public Animal{
	public:
	void Sound(){
		cout<<"Boo Boo..........."<<endl;
	}
	void eat(){
		cout<<"Meat"<<endl;
	}
};
class Cat : public Animal {
	public:
	void Sound(){
		cout<<"Meow Meow........."<<endl;
	}
	void eat(){
		cout<<"Milk"<<endl;
	}
};
class Cow : public Animal{
	public:
	void Sound(){
		cout<<"Ba Ba............."<<endl;
	}
	void eat(){
		cout<<"Grass......"<<endl;
	}
};
int main(){
	Dog dog1;
	Cat cat1;
	Cow cow1;
	dog1.Sound();
	cat1.eat();
	cow1.eat();
}