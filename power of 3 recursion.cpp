#include<iostream>
#include<math.h>
using namespace std;

int powerofthree(int i)
{
	if(i==1)
	{
		cout<<"True";
	}
	
	else if(i%3==0)
	{
		return powerofthree(i/3); 
	}
		
	else 
	{
		cout<<"False";
	}

}

int main()
{
	int n;
	cout<<"Enter value: "<<endl;
	cin>>n;
	powerofthree(n);
}
