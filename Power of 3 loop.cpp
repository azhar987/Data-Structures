#include<iostream>
#include<math.h>
using namespace std;

void powerofthree(int n)
{
	bool flag=false;
	int i=0;
	
	do
	{
		if(n==pow(3,i))
		{	
			cout<<"True"<<endl<<endl;
			flag=true;
		}
			i++;
	}
	
	while(i<n);
	
	if(flag==false)
	{
		cout<<"False";	
	}
}

int main()
{
	int n;
	cout<<"Enter number: "<<endl<<endl;
	cin>>n;
	cout<<endl;
	powerofthree(n);
	
}
