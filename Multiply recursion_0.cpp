#include<iostream>
using namespace std;

int multiply(int a,int b)
{
	if(a==1)
	{
		return b;
	}
	
	return b+multiply(a-1,b);
}

int main()
{
	int x,y;
	cout<<"Enter multiplier: ";
	cin>>x;
	cout<<endl<<"Enter multiplicand: ";
	cin>>y;
	cout<<endl<<"Answer: "<<multiply(x,y)<<endl;
}
