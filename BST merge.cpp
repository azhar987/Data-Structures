#include<iostream>
using namespace std;

class Node 
{
	public:
		int data;
		Node* left;
		Node* right;
		Node()
		{
			data = 0;
			left = NULL;
			right = NULL;
		}
};

class BST 
{
	private:
		Node* root = new Node;

	public:
		BST() 
		{	
			root = NULL;
		}
	
		bool isEmpty()
		{
			if(root==NULL)
			{
				return true;
			}
		
			else 
			{
				return false;
			}
		}
		
		void insert(int val)
		{	
			Node* temp;
			Node* temp1 = NULL;
			Node* n;
			
			n = new Node;
			n->data = val;
			n->left = NULL;
			n->right = NULL;
		
			if (isEmpty())
				root = n;
		
			else
			{
				temp = root;
				while (temp != NULL)				
			{
				temp1 = temp;
				
				if (temp->data == val)
				{
					cout << "Insertion of duplicates is not allowed" << endl;
					return;
				}
			
				else if (temp->data > val)
					temp = temp->left;
			
				else
					temp = temp->right;
			}
			
			if (temp1->data > val)
				temp1->left = n;
			
			else
				temp1->right = n;
		}
	}

	Node* getRoot() 
	{
		return root;
	}
	
	int totalLeafNodes(Node* root)
	{
		if (root==NULL)
			return 0;
			
		if (root->left == NULL && root->right == NULL)
			return 1;
		
		else
			return totalLeafNodes(root->left) + totalLeafNodes(root->right);
	}
	
	int height(Node* root) 
	{
		int leftHeight;
		int rightHeight;
		
		if (root == NULL)
			return -1;
		
		else
		{
			leftHeight = height(root->left);
			rightHeight = height(root->right);
		
			if (leftHeight > rightHeight)
				return(leftHeight + 1);
		
			else 
				return(rightHeight + 1);
		}
	}
	
	void inorder(Node* root)
	{
		if (root == NULL) {
			return;
		}
		
		inorder(root->left);
		cout << root->data << "\t";
		inorder(root->right);
	}

	void mergeBST(Node *root,Node *root1)
	{
		if(root==NULL)
		{
			return;
		}
		
		mergeBST(root->left, root1);
   
    	insert(root->data);
   
   		mergeBST(root->right, root1);
   	
	}
};

int main()
{
	BST bst1;
	BST bst2;
	
	bst1.insert(11);
	bst1.insert(3);
	bst1.insert(40);
	bst1.insert(1);
	bst1.insert(41);
	bst1.insert(13);
	bst1.insert(23);
	
	Node *root = bst1.getRoot();
	
	cout<<"Traversal of 1st tree: "<<endl<<endl;
	bst1.inorder(root);
	cout << endl<<"________________________________________________________________"<<endl<<endl;
	cout<<"Leaf count of 1st tree: "<<endl<<endl<<bst1.totalLeafNodes(root);
	cout << endl<<"________________________________________________________________"<<endl<<endl;
	cout<<"Height of 1st tree: "<<endl<<endl<<bst1.height(root);
	cout << endl<<"________________________________________________________________"<<endl<<endl;
	
	bst2.insert(8);
	bst2.insert(4);
	bst2.insert(10);
	bst2.insert(2);
	bst2.insert(6);
	bst2.insert(12);
	bst2.insert(9);
	
	Node *root1 = bst2.getRoot();
	
	cout<<"Traversal of 2nd tree: "<<endl<<endl;
	bst2.inorder(root1);
	cout << endl<<"________________________________________________________________"<<endl<<endl;
	cout<<"Merging trees: "<<endl<<endl;
	bst2.mergeBST(root,root1);
	bst2.inorder(root1);
}

