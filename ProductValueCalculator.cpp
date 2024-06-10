#include<iostream>
using namespace std;

class Product{
	public:
		void Input(){
			cout<<"Input the name,price and score: ";
			cin>>name>>price>>score;
		};
		double Contrast()const{
			return score / price;
		};
		void print()const{
			cout<<"name: "<<name<<" price: "<<price<<" score: "<<score; 
		};
	private:
		string name;
		double price;
		double score;
};

int main()
{
 	Product c1;
 	c1.Input();
 	c1.print();
 	cout<<"contrast: "<<c1.Contrast();
    system("pause");
 	return 0;
}
