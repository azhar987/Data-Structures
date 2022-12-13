//implementation of queue and dequeue through linklist
#include<iostream>
using namespace std;

class node {
	public:
		int data;
        node *next;
		node(int val) {
			data= val;
            next=NULL;
		}

};
class queue {
	public:
		node *rare;
        node *front;
		int length;
        int size;

	
		queue() {
			rare= NULL;
            front=NULL;
			length=0;
            size=5;
		}
    bool isempty()
    {
        if(front==NULL)
        {
            return true;
        }
        return false;
    }
    bool isfull()
    {
        if(length==size)
        {
            return true;
        }
        return false;
    }

    
    void enque(int val)
    {   
        if(front==NULL)
        {
            node *n=new node(val);
            n->next=NULL;
            rare = n;
          front=n;
            length++;
            return;
        }
        else
        {
            node *n=new node(val);
            rare->next=n;
            n->next=NULL;
            length++; 
            rare=n;
        }

    }
    void deque()
    {
        if(front==NULL)
        {
            cout<<"it is empty";
        }
        else
        {
            node*temp;
            temp=front;
            temp=temp->next;
            delete front;
            front=temp;
            length--;

        }
        

    }
    void display()
    {
        if(isempty())
        {
            cout<<"it is empty"<<endl;
        }
        else
        {
            node*temp;
            temp=front;
            while(temp!=NULL)
            {
                   cout<<temp->data<<endl;
            temp = temp ->next;
            }
        }
    }
	
};

int main()
{
    queue obj;
    cout<<"enque"<<endl;
    obj.enque(3);
    obj.enque(4);
    obj.enque(5);
    obj.display();
    cout<<"Deque"<<endl;
    obj.deque();
    obj.display();
}
