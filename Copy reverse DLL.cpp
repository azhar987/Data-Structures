#include<iostream>
using namespace std;

class node //making node class
{
	public:
		node *next;
		node *prev;
		int data;
		node(int val) //node constructor with val as parameter
		{
			next=NULL;
			prev=NULL;
			data=val;
		}
};
//DLL class which will have all the functions
class DLL
{
	private:
		node *head;
		int length;
	
	public:
		DLL() //DLL constructor
		{
			head=NULL;
			length=0;
		}
	
	bool isEmpty() //checking if the DLL is empty
	{
		if(head==NULL)
		{
			return true;
		}
		else
			return false;
	}
		
	void insert(int val,int pos) //insertion at position
	{
		if(pos>length+1 || pos<1) //pos should be between 1 and length+1
		{
			return;
		}
		node *n = new node(val); //making new node
		
		if(pos==1) //if inserting at head
		{
			if(isEmpty()) //if list is empty
			{
				head=n; //making head as n
			}
			else
			{	
				n->next=head; //putting n before heas
				head->prev=n; //connecting head to n
				head=n; //making head as n
			}
		}
		
		else
		{
			node *temp=head; //moving temp to head
			
			for(int i=1;i<pos-1;i++) //for loop to reach position
			{
				temp=temp->next; //moving forward
			}
			n->next=temp->next; //attaching node
			temp->next=n;
			n->prev=temp;
		}
		
		length++; //increasing length
	}
		
	void print() //printing the DLL
	{	
			node *temp=head;
			while(temp!=NULL) //will move till the last node
			{
				cout<<temp->data<<"\t";
				temp=temp->next;
		}
	}

	void copyreverse(DLL dll) //copy function with linklist as parameter
	{ 
		
		if(dll.isEmpty()) 
		{
			return;
		}
		
		for(int i=1;i<=dll.len();i++)
		{
			insert(dll.get(i),i); //inserting values in ith index
		}
	}
	
	void reverse()
	{
		node *temp = NULL; //initializing temp as NULL
		node *curr = head; //moving curr to head
		
		while (curr != NULL) //moving till last node
		{
			temp = curr->prev; //reversing the list
			curr->prev = curr->next;
			curr->next = temp;			
			curr = curr->prev;
		}
		
		if(temp!=NULL) //moving head
		
			head = temp->prev;
	}

	
	int get(int pos) //used to get the value on positior
	{
		if(length==0) //list is emoty
		{
			return 0;
		}
	
		if(pos>length+1) //if position is greater then the length
		{
			return 0;
		}
			
		else
		{	
			node *temp=head;	
			
			for(int i=1;i<pos;i++) //moving till required node
			{
				temp=temp->next;
			}
			return temp->data; //returning its data
		}
	}
	
	int len() //returns length of list
	{
		return length;
	}

};
	
int main()
{
	DLL dll; //making 1st list
	DLL dll2; //making 2nd list
	//inserting values at pos
	dll.insert(2,1);
	dll.insert(3,2);
	dll.insert(4,3);
	dll.insert(5,4);
	dll.print(); //printing list
	dll.reverse(); //calling reverse function
	dll2.copyreverse(dll); //copying reversed list in 2nd list
	cout<<endl<<endl<<"_______________________"<<endl<<"Copied List: "<<endl<<endl;
	dll2.print(); //printing list
}
