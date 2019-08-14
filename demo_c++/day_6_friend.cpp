#include<iostream>
using namespace std;
class B;
class A
{
	public:
	void display(B& temp);
	
};
class B
{
	public:
	friend void A::display(B&);
	private:
	int a=10;
	int b=20;
};

void A::display(B& temp)
	{
		cout<<temp.a<<" "<<temp.b;
	}
	
int main()
{
	B x;
	A y;
	y.display(x);
	system("pause");
}