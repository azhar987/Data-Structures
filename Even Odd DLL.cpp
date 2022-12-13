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
	
//	bool isEven() // **this function isnt working**
//	{
//		node *curr=head;
//		while(curr!=NULL)
//		{
//			if(curr->data%2==0)
//			{
//				return true;
//			}
//			curr=curr->next;
//		}
//		return false;
//	}
//	
//	void copyeven(DLL dll) //**this function isnt working**
//	{
//		if(dll.len()==0)
//		{
//			return;
//		}
//		for(int i=1;i<=dll.len();i++)
//		{
//			insert(dll.geteven(i),i); 
//		}
//	}
//			
//	
//	void copyodd(DLL dll) //**this function isnt working
//	{
//		if(dll.len()==0)
//		{
//			return;
//		}
//		for(int i=1;i<=dll.len();i++)
//		{
//			insert(dll.getodd(i),i); 
//		}
//			
//	}
//	
//	int  geteven(int pos) //**this function isnt working**
//	{
//		if(length==0) 
//		{
//			return 0;
//		}
//		if(pos>length+1) 
//		{
//			return 0;
//		}
//		else
//		{	
//			node *even =head;	
//			
//			for(int i=1;i<pos;i++)
//			{
//				even=even->next;
//			}
//			if(even->data % 2 == 0)
//			{
//					return even->data;
//			}
//			else
//			{
//				return 0;
//			}
//		}
//	}
//	
//	int getodd(int pos) //**this fucntion isnt working**
//	{
//		if(length==0) 
//		{
//			return 0;
//		}
//		if(pos>length+1) 
//		{
//			return 0;
//		}
//		else
//		{	
//			node *odd =head;
//			for(int i=1;i<pos;i++)
//			{
//				odd = odd->next;
//			}
//			if(odd->data%2!=0)
//			{
//				return odd->data;
//				
//			}
//				
//		}
//	}

	int len() //returns length of list
	{
		return length;
	}
	
	void even(DLL dll) //checks even elements in the list
	{
		node *temp = dll.head; //moving temp to the head of list
		
		while(temp!=NULL) //moving till last node
		{	
			if(temp->data%2==0) //checking if data is even
			{
				cout<<temp->data<<"\t"; //printing the data
			}
			temp=temp->next; //moving forward
		}
	}
	
	void odd(DLL dll) //checks odd elements in the list
	{
		node *temp=dll.head; //moving temp to the head of list
	
		while(temp!=NULL) //moving till last node
		{
			
			if(temp->data%2!=0) //checking if data is odd
			{
				cout<<temp->data<<"\t"; //printing data
			}
			
			temp=temp->next; //mvoing forward
		}
	}	
};

int main()
{
	DLL dll; //creating 1st list
	DLL dll2; //creating 2nd list
	DLL dll3; //creating 3rd list
	
	//insertion at position
	dll.insert(1,1);
	dll.insert(2,2);
	dll.insert(2,3);
	dll.insert(3,4);
	dll.insert(5,5);
	dll.insert(6,6);
	dll.insert(7,7);
	dll.insert(9,8);
	dll.insert(11,9);
	dll.insert(12,10);
	dll.print();
	

	cout<<endl<<endl<<"_______________________"<<endl<<endl<<"Even elements: "<<endl<<endl;
//	dll2.copyeven(dll);
//	dll2.print();
	dll2.even(dll);	//calling even function
	
	cout<<endl<<endl<<"_______________________"<<endl<<endl<<"Odd elements: "<<endl<<endl;
//	dll3.copyodd(dll);
//	dll3.print();
	dll3.odd(dll); //calling odd fucntion
}
