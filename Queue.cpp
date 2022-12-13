#include<iostream>
using namespace std;
class Node{
	public:
		Node *next;
		int data;
		Node (int val)
		{
			data = val;
		}
};
class Queue{
	private:
		Node *rear;
		Node *front;
		int length;
		int size;
		
	public:
		Queue()
		{
			rear=NULL;
			front=NULL;
			length=0;
			size=4;
		}
		
	bool isEmpty()
	{
		if(front==NULL)
			return true;
		else
			return false;
	}
	
	bool isFull()
	{
		if(length==size)
			return true;
		else
			return false;
	}
	

	void enqueue(int n)
	{
		if(front==NULL)
		{
			front=new Node(n);
			front->data=n;
			front->next=NULL;
			rear = front;
		}
		else
		{
			Node*temp=new Node(n);
			rear->next=temp;
			rear=temp;
			temp->next=NULL;
		}
	}
	
	void print()
	{
		if(front==NULL)
		{
			cout<<"List is empty.";
			return;
		}
		else
		{	
			Node* temp=front;
			while(temp->next!=NULL)
			{
				cout<<" "<<temp->data<<endl;
				temp=temp->next;
			}
		
		}
	}
	
	void dequeue()
	{
		if(front==NULL)
		{
			cout<<"Queue underflow.";
			return;
		}
		else
		{
			Node *temp;
			temp=front;
			front=front->next;
			delete temp;
			length--;	
		}
		
	}
};

int main()
{
	Queue q;
	cout<<"Enqueue: "<<endl;
	q.enqueue(7);
	q.enqueue(4);
	q.enqueue(6);
	q.enqueue(5);
	q.enqueue(2);
	q.print();
	cout<<"Dequeue: "<<endl;
	q.dequeue();
	q.print();
}
