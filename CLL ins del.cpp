#include<iostream>
using namespace std;

class node
{
	public:
		node *next;
		int data;
		node(int val)
		{
			next=NULL;
			data=val;
		}
};

class CLL
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
		
	void insertathead(int val)
	{
		
		node *n = new node(val);
		
			if(isEmpty())
			{
				head=n;
				head->next=head;
				
			}
			else
			{	
				n->next=head;
				node *temp=head;
				while(temp->next!=head)
				{
					temp=temp->next;
				}
				
				
				head=n;
				temp->next = head;
			}
			length++;
		}
	
	
	void print()
	{	
			node *temp=head;
			for(int i=1;i<=length;i++)
			{
				cout<<temp->data<<"\t";
				temp=temp->next;
			}
	}
	
	void deletionatend()
	{	
		if(isEmpty())
		{
			cout<<"List is empty."<<endl;
			return;
		}
		
		node *temp = NULL;
		node *temp1 = head;
	
		while(temp1->next!=head)
		{
			temp=temp1;
			temp1=temp1->next;
		}
		
		temp->next=head;
		delete temp1;	
		length--;
	}	

};

int main()
{
	CLL c;
	c.insertathead(2);
	c.insertathead(3);
	c.insertathead(4);
	c.insertathead(9);
	c.print();
	cout<<endl<<endl<<"__________________________________________"<<endl<<endl<<"After deletion: "<<endl<<endl;
	c.deletionatend();
	c.print();
}
