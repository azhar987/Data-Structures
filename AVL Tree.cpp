#include <iostream>
using namespace std;
class Node 
{
    public:
        int data;
        int height;
        Node* left;
        Node* right;
        Node (int val) 
		{
            this -> data = val;
            left = right = NULL;
            height = 0;
        }
};
class AVL 
{
    Node* root;
	Node *temp;
	Node *temp2; 
	Node *temp3;
    int len;
    void makeEmpty(Node* r);
    Node* insert(Node* r, int val);
    Node* findMax(Node* r);
    Node* findMin(Node* r);
    Node* remove(Node* r, int val);
    int height(Node* t) 
	{
        if (t == NULL) 
		{
            return -1;
        }
        else 
		{
            return t -> height;
        }
    }
    int getBalance(Node* t) 
	{
        if (t == NULL) 
		{
            return 0;
        }
        else 
		{
            return height(t -> left) - height(t -> right);
        }
    }
    void inOrder(Node* r);
    Node* SingleLeft(Node* &r);
    Node* SingleRIght(Node* &r);
    Node* DoubleLeftRight(Node* &r);
    Node* DoubleRightLeft(Node* &r);
public:
    AVL() 	
	{
       	root = temp = temp2 = temp3 = NULL;
       	len = 0;
   	}
    void insert(int val) 
	{
        root = insert(root, val);
    }
    void remove(int val) 
	{
        root = remove(root, val);
    }
    void display() 
	{
        inOrder(root);
        cout << endl;
    }
};
int main() 
{
    return 0;
}
Node* AVL::SingleLeft(Node* &A)
{
	Node* newRoot = A->right;
	A->right = newRoot->left;
	newRoot->left = A;
	A->height = max(height(A ->left), height(A ->right)) + 1;
	newRoot ->height = max(height(newRoot->right), A->height) + 1;
	return newRoot;
}
Node* AVL::SingleRIght(Node* &C)
{
	Node* newRoot = C->left;
	C->left = newRoot->right;
	newRoot->right = C;
	C->height = max(height(C ->left), height(C ->right)) + 1;
	newRoot ->height = max(height(newRoot->left), C->height) + 1;
	return newRoot;
}
Node* AVL::DoubleLeftRight(Node*& t)
{
	t->left = SingleLeft(t->left);
	return SingleRIght(t);
}
Node* AVL::DoubleRightLeft(Node*& t)
{
	t->right = SingleRIght(t->right);
	return SingleLeft(t);
}

