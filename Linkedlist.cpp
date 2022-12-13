#include<iostream>
using namespace std;

struct node{
	int data;
	node *next;
};

class LinkedList
{
	private:
		node *head;
	
	public:
		
	LinkedList()
	{
		head = NULL;
		
	}
	
void insertion(int val)
{
	if (head == NULL)
	{
		head = new node;
		head->data=val;
		head->next=NULL;
	}
		
		node *temp=head;
		while(temp!=NULL)
		{
			node *temp1;
			temp1=new node;
			temp1= temp -> next; 
			temp1 -> data = val;
			temp1->next = NULL;
		}	
		temp = temp->next;
		
}

void insertionatPos(int key, int val)
{
	if (head==NULL)
	{
		head = new node;
		head -> data = val;
		head->next=NULL;
	}
	node *temp=head;
	while(temp->next!=NULL)
	{
		if(temp->data==key)
		{
			node *temp1;
			temp1 = temp->next;
			temp1->data = val;
			temp->next=temp1->next;
		}
		temp=temp->next;
	}
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
	
	if (head == NULL)
	{
		cout<<"List is empty."<<endl;
		return;
	}
	node *temp;
	temp=head;
	if(head->data==val)
	{
		head=head->next;
		delete temp;
		return;
	}
	while(temp->next!=NULL)
	{
		if(temp->next->data==val)
		{
			node *temp1;
			temp1=temp->next;
			temp->next=temp->next->next;
			delete temp1;
			return;
		}
		temp=temp->next;
	  }  
}
};
int main()
{
	LinkedList l;
	l.insertion(1);
	l.insertion(2);
	l.insertion(3);
	l.insertion(4);
	l.insertionatPos(3,90);
	l.print();
	return 0;
}
