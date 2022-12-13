#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;

int main()
{
	int *val, *rows, *cols;
	int maxr, maxc, i , j;
	cout<<"Enter the dimension of the array(row col): " ;
	cin>>maxr>>maxc;
	
	val= new int[maxr * maxc];
	rows=new int[maxr];
	cols=new int[maxc];
	
	for(i=0; i<maxr; i++)
	{
		cout<<"\nEnter elements for row"<<i+1<<" ";
		rows[i]=0;
		for(j=0; j<maxc; j++)
		{
			cin>>val[i*maxc +j];
			rows[i]=rows[i]+val[i *maxc+j];
		}
	}
		for (j=0; j<maxc ;j++)
		{
			cols[j]=0;
			for(i=0;i<maxr;i++)
			{
				cols[j]=cols[j]+ val[i *maxc+j];
				
			}
		}
		cout<<"\nThe given array in "<<maxr<<" x "<<maxc<<" 2 dimensional(along with rowsum anf colsum) is :"<<endl<<endl<<endl ;
		for(i=0;i<maxr;i++)
		{
			for(j=0;j<maxc; j++)
			{
				cout<<val[i*maxc +j]<<"\t" ;
			}
			cout<<rows[i]<<"\n" ;
		}
		for(j=0; j<maxc; j++)
		{
			cout<<cols[j]<<"\t" ;
		}
		cout<<"\n";
		delete[] val;
		delete[] cols;
		delete[] rows;
		//getch();
		return 0;
	
	
}
