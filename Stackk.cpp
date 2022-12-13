#include<iostream>
using namespace std;
class Node
{
	public:
		Node *next;
		int data;
		Node (int val)
		{
			data=val;
		}
};
class Stack
{
	public:
		Node *top;
		Node *temp;
		Stack()
		{
			top=NULL;
			temp=NULL;
		}
	bool isEmpty()
	{
		if(top==NULL)
			return true;
		else
			return false;
	}
	void push(int value)
	{
		if(isEmpty())
		{
			temp = new Node(value);
			temp->next=NULL;
			top=temp;	
		}	
		else
		{
			temp = new Node(value);
			temp->next=top;
			top=temp;
		}
	}
	void pop()
	{
		if(isEmpty())
		{
			cout<<"Stack is empty"<<endl;
		}
		else
		{
			temp=top;
			top=top->next;
			delete temp;
		}	
	}
	void print()
	{
		if(top==NULL)
		{
			cout<<"Stack is empty"<<endl;
			return;
		}
		else
		{	
			temp=top;
			while(temp!=NULL)
			{
				cout<<temp->data<<endl;
				temp=temp->next;
				
			}
		}
	}
	
	void peek()
	{
	
		cout<<top->data<<endl;	
		}
	
};

int main()
{
	Stack stackk;
	stackk.push(10);
	stackk.push(20);
	stackk.push(30);
	stackk.push(40);
	cout<<"Peek: "<<endl;
	//stackk.print();
	stackk.peek();
	cout<<"\nBefore Pop: "<<endl;
	stackk.print();
	stackk.pop();
	cout<<"\nAfter Pop: "<<endl;
	stackk.print();
}
