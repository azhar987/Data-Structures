#include <iostream>
using namespace std;
class Stack 
{
    public:
        int* arr; 
		int *temp;
        int top; 
		int size;
		int len;
        Stack() 
		{
            size = 5;
            arr = new int[size];
            temp = NULL;
            top = -1;
            len = 0;
        }
        bool isEmpty() 
		{
            if (top == -1) 
			{
                return true;
            }
			else 
			{
                return false;
            }
        }
        bool isFull() 
		{
            if (top == size - 1) 
			{
                return true;
            }
            else 
			{
                return false;
            }
        }
        void push(int val) 
		{
            if (isFull()) 
			{
                cout << "STACK OVERFLOW" << endl;
            }
            else 
			{
                arr[++top] = val;
                len++;
            }
        }
        void pop() 
		{
			if (isEmpty()) 
			{
				cout << "Stack Underflow" << endl;
				return;
			}
			else 
			{
				top--;
                len--;
				return;
			}
		}
        int Peek() 
		{
			if (isEmpty()) 
			{
				cout << "Empty Stack" << endl;
				return -1;
			}
			else 
			{
				return top[arr];
			}
        }
        void print() 
		{
			while(!isEmpty()) 
			{
				cout << "Element: " << Peek() << endl;
				pop();
			}
		}
};
int main() 
{
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.print();
    cout <<"\nAFTER POP()" << endl;
    st.pop();
    cout << "\nTOP ELEMENT" << endl;
    st.Peek();
    return 0;
}
