#include<iostream>
using namespace std;

//calculate factroail of all integer
int profun(int val)
{
	if(val==1)
	return 1;
	
	else
	{
		cout<<"val: "<<val<<endl;
		return val*profun(val-1);
		
	}
}

//calculate sum of all integer
int sumfun(int val)
{
	if(val==1)
	return 1;
	
	else
	{
		cout<<"val: "<<val<<val-1<<endl;
		return val+sumfun(val-1);
		
	}
}
//print Table
int Table(int t,int val)
{
	if(val==11)
	return 10;
	
	else
	{
		cout<<t<<" x"<<val<<" ="<<t*val<<endl;
		Table(t, val+1);
	}
}
//Print even
int even(int val)
{
	if(val==1)
	return 1;
	
	else
	{
		if(val%2==0)
		cout<<val<<endl;
		even(val-1);
	}
}
//Print ODD
int odd(int val)
{
	if(val==0)
	return 0;
	
	else
	{
		if(val % 2 !=0)
		cout<<val<<endl;
		odd(val -1);
	}
}

int main()
{
	//even(10);
	odd(10);
	Table(10,9);
	//cout<<"the product is "<<profun(5);
	return 0;
}
