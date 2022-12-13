#include <iostream>
using namespace std;

//making a class of node where we're declaring the value and initializing the node 'next' as NULL.
class node 
{
	public:
		int data;
		node *next;
		node(int value)
		{
			data=value;
			next=NULL;	
		}	
	
};
//making a class of linked list. this will have constructor and all the functions.
class linklist
{
	private:
		node *head;
		int len;
	//constructor.
	public:
		linklist()
		{
			head=NULL;
			len=0;
		}
	//this function will insert the values in the linked list one after the other.	
	void onlyinsert(int val)
	{
		node *n=new node(val); //making  a new node
		if(head==NULL) //list is empty
		{
			n->next=NULL;
			head=n;
		}
		else
		{
		node *curr=head;
		for(int i=1;i<len;i++) //using a for loop where i will be less than length
		{
			curr=curr->next;
		}
		n->next=NULL;
		curr->next=n;
	}
	len++;
	}
	
	void print() //printing the entire list
	{
		node *curr=head;
		while(curr!=NULL) //moving till the last node
		{
			cout<<curr->data<<"\t";
			curr=curr->next;
		}
	}
void movetolast() //a function that will move the last node to the front of the list
{
	node*temp=head;
	node*curr=head;
	for(int i=1;i<len;i++) //traversing list
	{
		temp=curr; //temp will stop one node before curr.
		curr=curr->next;
	}
	temp->next=NULL; //making temp the last node
	curr->next=head; // moving curr before head i.e making it the first node
	head=curr; //moving head to curr.
}
};
int main()
{
	linklist l; //making object of class
	l.onlyinsert(1);
	l.onlyinsert(2);
	l.onlyinsert(4);
	l.onlyinsert(5);
	l.onlyinsert(2);
	l.onlyinsert(2);
	l.onlyinsert(3);
	l.print();
	cout<<endl<<"____________________________________________________"<<endl<<endl;
	l.movetolast(); //moving the last node to the first node
	l.print();
}
