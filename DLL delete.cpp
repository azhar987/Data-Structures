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
	
	void deletion(int pos)
	{
		if(pos>length || pos<1)
		{
			return;
		}
		
		if(isEmpty())
		{
			cout<<"List is empty."<<endl;
			return;
		}
		
		if(pos==1)
		{
			node *temp=head;
			head=head->next;
			delete temp;
			head->prev=NULL;
		}
		
		else
		{
			node *temp = NULL;
			node *temp1 = head;
			for(int i=1;i<pos;i++)
			{
				temp=temp1;
				temp1=temp1->next;
			}
			
			temp->next=temp1->next;
			delete temp1;
		}	
		length--;
	}	
};

int main()
{
	DLL d;
	d.insert(2,1);
	d.insert(3,2);
	d.insert(4,3);
	d.insert(9,4);
	d.print();
	cout<<endl<<endl<<"__________________________________________"<<endl<<endl<<"After deletion: "<<endl<<endl;
	d.deletion(3);
	d.print();
}
