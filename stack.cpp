#include<iostream>
using namespace std;
struct node{
	node *next;
	int data;
};
class Stack{
	public:
	node *top;
	node *temp;
	Stack(){
		top=NULL;
		temp=NULL;
	}
	bool isEmpty(){
		if(top==NULL){
			return true;
		}
		else{
			return false;
		}
	}
	void push(int val){
		if(isEmpty()){
			top=new node();
			top->data=val;
			top->next=NULL;
			
		}
		else{
			temp=new node;
			temp->data=val;
			temp->next=top;
			top=temp;
		}
	}
	void pop(){
		if(isEmpty()){
			cout<<"Stack is Empty"<<endl;
			
		}
		else{
			temp=new node();
			temp=top;
			top=top->next;
			delete temp;
			temp=NULL;
		}
	}
	void peek(){
		if(isEmpty()){
			cout<<"stack is empty"<<endl;	
		}
		else{
			cout<<top->data<<endl;
		}
	}
	void Display(){
		if(isEmpty()){
			cout<<"Stack is Empty";
		}
		else{
			temp=new node();
			temp=top;
			while(temp!=NULL){
				cout<<temp->data<<endl;
				temp=temp->next;
			}
		}
	}
		
	
};
int main(){
	Stack obj1;
	obj1.push(1);
	obj1.push(2);
	obj1.push(3);
	obj1.push(4);
	obj1.push(5);
	//obj.peek();
	obj1.pop();
	obj1.peek();
	obj1.Display();
	return 0;
}