#include<iostream>
using namespace std;

class node
{
	public:
		node *next;
		node *prev;
		int data;
		node(int val)
		{
			next=NULL;
			prev=NULL;
			data=val;
		}
};

class DLL
{
	private:
		node *head;
		int length;
	
	public:
		DLL()
		{
			head=NULL;
			length=0;
		}
	
	bool isEmpty()
	{
		if(head==NULL)
		{
			return true;
		}
		else
			return false;
	}
		
	void insert(int val,int pos)
	{
		if(pos>length+1 || pos<1)
		{
			return;
		}
		node *n = new node(val);
		
		if(pos==1)
		{
			if(isEmpty())
			{
				head=n;
			}
			else
			{	
				n->next=head;
				head->prev=n;
				head=n;
			}
		}
		
		else
		{
			node *temp=head;
			
			for(int i=1;i<pos-1;i++)
			{
				temp=temp->next;
			}
			n->next=temp->next;
			temp->next=n;
			n->prev=temp;
		}
		
		length++;
	}
	
	void print()
	{	
			node *temp=head;
			while(temp!=NULL)
			{
				cout<<temp->data<<"\t";
				temp=temp->next;
		}
	}
	
	int get(int pos) 
	{
		if(length==0) 
		{
			return 0;
		}
	
		if(pos>length+1) 
		{
			return 0;
		}
			
		else
		{	
			node *temp=head;	
			
			for(int i=1;i<pos;i++) 
			{
				temp=temp->next;
			}
			return temp->data; 
		}
	}
	
	int len() 
	{
		return length;
	}
	
	void FrontBackSplit(DLL &dll,DLL &dll1,DLL &dll2)
	{
		dll1.head=dll.head;
	
		node *temp1=dll1.head;
		node *temp=dll2.head;
	
		for(int i=0;i<=(dll.len()/2-1)+1;i++)
		{
			temp=temp1;
			temp1=temp1->next;
		}
		
		temp->next=NULL;
		temp1->prev = NULL;
		
		dll2.head = temp1;
	}
};

int main()
{
	DLL dll;
	DLL dll1;
	DLL dll2;
	dll.insert(2,1);
	dll.insert(3,2);
	dll.insert(4,3);
	dll.insert(9,4);
	dll.insert(8,5);
	dll.print();
	cout<<endl<<endl<<"__________________________________________"<<endl<<endl;
	dll1.FrontBackSplit(dll,dll1,dll2);
	cout<<"1st half of list: "<<endl<<endl;
	dll1.print();
	cout<<endl<<endl<<"__________________________________________"<<endl<<endl;
	cout<<"2nd half of list: "<<endl<<endl;
	dll2.print();
}
