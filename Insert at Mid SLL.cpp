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
		if(head==NULL)
		{
			n->next=NULL;
			head=n;
		}
		else
		{
		node *curr=head;
		for(int i=1;i<len;i++)
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
		while(curr!=NULL)
		{
			cout<<curr->data<<"\t";
			curr=curr->next;
		}
	}
	
	void midinsert(int val)
	{
		node *temp=head;
		node *n = new node(val); //making new node with val as parameter
		for(int i=1;i<len/2;i++) //moving to the middle of the list
		{
			temp=temp->next;
		}
		n->next=temp->next; //attaching the node
		temp->next=n;
		len++; //increasing length
	}
};

int main()
{
	linklist l; //making object of class
	l.onlyinsert(1);
	l.onlyinsert(2);
	l.onlyinsert(4);
	l.onlyinsert(5);
	l.print();
	cout<<endl<<"____________________________________________________"<<endl<<endl;
	l.midinsert(7); //inserting value at middle
	l.print();

}
