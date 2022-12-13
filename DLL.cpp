#include<iostream>
using namespace std;
struct node{
	node* next;
	node *prev;
	int data;
};
 
class DLL
{
	private:
		node *head;
	public:
		DLL()
		{
			head==NULL;
		}
	void insertion(int val)
	{
		if (head==NULL)
		{
			node *head= new node;
			head->data=val;
			head->next=NULL;
			head->prev=NULL;
			return;
		}
		node *temp;
		temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		node *temp1=new node;
		temp1->next=temp->next->prev;
		temp1->prev=temp;
		temp1->data=val;
		temp->next=temp1;
		return;
	}
	void print()
{
	if(head==NULL)
	{
		cout<<"List is empty"<<endl;
		return;
	}
	node *temp;
	temp =head;
	while(temp->next!=NULL)
	{
		cout<<temp->data<<endl;
	temp=temp->next;
	}
	
	 return;
}
	void deletion(int val)
	{
		if(head==NULL)
		{
			cout<<"List is empty."<<endl;
			return;
		}
		node *temp;
		temp=head;
		if(head->data==val)
		{
			head=head->next;
			head->prev=NULL;
			delete temp;
			return;
		}
		while(temp!=NULL)
		{
			if(temp->data==val)
			{
				temp->next->prev=temp->prev;
				temp->prev->next=temp->next;
				delete temp;
				return;
			}
			temp=temp->next;
		}
	}
};

int main()
{
	DLL d;
	d.insertion(1);
	d.insertion(4);
	d.insertion(3);
	d.insertion(9);
	d.print();
//	d.deletion(9);
//	d.print();
}
