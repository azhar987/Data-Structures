#include <iostream>
using namespace std;
//making a class of node where we're declaring the value and initializing the node 'next' as NULL.
class node 
{
    public:
        char data;
        node *next;
        node(char value)
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
    public:
    	//constructor
        linklist()
        {
            head=NULL;
            len=0;
        }
    //this will insert the values on given position
    void insert(int val,int pos)
    {
        if(pos>len+1) //if insertion further than the last index
        {
            return;
        }
        
        node *n=new node(val); //making new node 
		if(pos==1) //insrtion at head
        {
            n->next=head;
            head=n;
        }
        else
        {
        node *curr=head;
        for(int i=1;i<pos-1;i++)
        {
            curr=curr->next;
        }
        n->next=curr->next;
        curr->next=n;
    }
    len++;
    }
    
    void reverse() //this qwill reverse the list
    {
        node *curr=head;
		node *temp=NULL;
		node *temp1=NULL;
		while(curr!=NULL) //to move the pointer
		{
			temp=curr->next;
			curr->next=temp1;
			temp1=curr;
			curr=temp;
		}
		head=temp1; //the last element will become first
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

    int length() //returns length of list
    {
        return len;
    }
    char getposition(int pos) //used to get the value on positior
    {
         node*curr=head;

        if(pos>len) //if length is less than the position
        {
            return 0;
        }
        
        else

        for(int i=1;i<pos;i++)
        {
			curr=curr->next;
		}
        
		return curr->data;}
 
    void copy(linklist l) //copies the list
		{
			int lee=l.length(); //stores the length of linkedlist
		
        	for(int i=1;i<=lee;i++)
        	{
            	insert(l.getposition(i),1); //inserts at 1st position
        	}
        
    }
 
    bool palin(linklist &l,linklist &l2) //checks if it is palindrome
    {
        node*curr=l.head;
        node*temp=l2.head;
        if(curr->data==temp->data)
        {
        	for(int i=1;i<=len;i++)
        	{
            	if(curr->data==temp->data)
            	{
                	curr=curr->next;
                	temp=temp->next;
        		}
        	}
        	cout<<"It is palindrome."<<endl;
    	}
        else
        
        	cout<<"It is not palindrome.";
    	
    }
};

int main()
{
    linklist l,l2; //making 2 objects of class
    l.insert('m',1); 
    l.insert('a',2);
    l.insert('d',3);
    l.insert('a',4);
    l.insert('m',5);
    l.print(); //printing list
    cout<<endl<<"_____________________________________________________________________"<<endl<<endl;
    cout<<"Copying list in reverse order in another list: "<<endl<<endl;
    l2.copy(l); //copying in reverse
    l2.print(); //printing 2nd list
    cout<<endl<<"_____________________________________________________________________"<<endl<<endl;
    cout<<"Checking if list is palindrome or not:"<<endl<<endl;
    l2.palin(l,l2); //tells if its palindrome
}
