#include <iostream>
using namespace std;

void common(int arr1[],int arr2[],int arr3[],int len)
{
    cout<<"Array 1: "<<endl<<endl;

    for(int i=0;i<len;i++)
	{
        cout<<arr1[i]<<"\t";
    }

    cout<<endl<<endl;
    cout<<"Array 2: "<<endl<<endl;

    for(int j=0;j<len;j++) 
	{
        cout<<arr2[j]<<"\t";
	}

    cout<<endl<<endl;
	cout<<"Common elements in both arrays are: "<<endl<<endl;
    
	int i = 0;
	int j = 0;
	int l = 0;
    
    while(i < len && j < len)
	{

        if(arr1[i] > arr2[j])
        {
			j++;
        }

  	    else if(arr1[i] < arr2[j])
        {
            i++;
        }

        else
		{
            arr3[l] = arr1[i];
            l++;
            i++;
            j++;
        }
    }

	for(int k = 0;k < l;k++)
    {
        cout<<arr3[k]<<"\t";
    }
}

int main()
{
    int len=7;

    int arr1[len]={1,2,3,5,5,1,5};
    int arr2[len]={1,2,5,7,5,1};
    int arr3[len]={};   

    common(arr1,arr2,arr3,len); 
}
