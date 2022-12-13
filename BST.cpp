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
		void insert(int x)
		{	
			Node* temp;
			Node* temp1 = NULL;
			Node* n;
			n = new Node;
			n->data = x;
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
				if (temp->data == x)
				{
					cout << "Insertion of duplicates is not allowed" << endl;
					return;
				}
				else if (temp->data > x)
					temp = temp->left;
				else
					temp = temp->right;
			}
			if (temp1->data > x)
				temp1->left = n;
			else
				temp1->right = n;
		}
	}

	Node* getRoot() 
	{
		return root;
	}

	void inorder(Node* root)
	{
		if (root == NULL) 
		{
			return;
		}
		inorder(root->left);
		cout << root->data <<endl;
		inorder(root->right);
	}

	Node* minValueNode( Node* x)
	{

			Node* temp = x;
		while (temp && temp->left != NULL)
			temp = temp->left;

		return temp;
	}

	Node* deleteNode( Node* root, int x)
	{

		if (root == NULL)
			return root;

		if (x < root->data)
			root->left = deleteNode(root->left, x);
		else if (x > root->data)
			root->right = deleteNode(root->right, x);
		else 
		{
			if (root->left == NULL and root->right == NULL)
				return NULL;

			else if (root->left == NULL) 
			{
				Node* temp = root->right;
				free(root);
				return temp;
			}
			else if (root->right == NULL) 
			{
				Node* temp = root->left;
				delete root;
				root = nullptr;
				return temp;
			}
			Node* temp = minValueNode(root->right);
			root->data = temp->data;
			root->right = deleteNode(root->right, temp->data);
		}
		return root;
	}


	bool search(int value)
	{
		Node* temp;
		bool found = false;
		if (root == NULL) 
		{
			cout << "The tree is empty." << endl;
			return false;
		}
		else
		{
			temp = root;
			while (temp != NULL && !found)
			{
				if (temp->data == value)
				{
					found = true;
					cout<<endl<<"Value found!"<<endl;
				}
				else if (temp->data > value)
				{
					temp = temp->left;
				}
				else
				{
					temp = temp->right;
				}
				
			}
		}
		 
		cout<<endl<<"Value not found!"<<endl;
		return found;
	}
	
	int totalLeafNodes(Node* root)
	{
		if (!root)
			return 0;
		if (root->left == NULL && root->right == NULL)
			return 1;
		else
			return totalLeafNodes(root->left) +
			totalLeafNodes(root->right);
	}
	
		int find_Height(Node* root, int x, int& temp)
	{
		int value;
		if (root == NULL) {
			return -1;
		}
		int leftHeight = find_Height(root->left, x, temp);

		int rightHeight
			= find_Height( root->right, x, temp);
		value = max(leftHeight, rightHeight) + 1;
		if (root->data == x)
			temp = value;

		return value;
	}

	int findHeight(Node* root, int x){
		int temp = -1;
		int maxHeight = find_Height(root, x, temp);
		return temp;
	}

};

int main() 
{
	int x,value;
	BST obj;
	obj.insert(10);
    obj.insert(30);
	obj.insert(50);
	obj.insert(20);
	obj.insert(80);
	obj.insert(70);
	obj.insert(90);
	
	Node* root = obj.getRoot();

	cout << "In order of the BST tree : "<<endl<<endl;
	obj.inorder(root);
	cout << endl<<"________________________________________________________________"<<endl<<endl;
	cout << "Enter the Node you want to delete : "<<endl<<endl;
	cin >> x;
	obj.deleteNode(root, x);
	cout <<endl<<"________________________________________________________________"<<endl<<endl;
	cout << "In order of the new BST tree is : "<<endl<<endl;
	obj.inorder(root);
	cout <<endl<<"________________________________________________________________"<<endl<<endl;
	cout<<"Enter value to search: "<<endl<<endl;
	cin>>value;
	obj.search(value);
			
}

