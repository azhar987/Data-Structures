#include<iostream>
#include<stack> //using stack library fro inbuilt functions
#include<string> //using string library
using namespace std;

bool ArePair(char opening,char closing) //using this function to check brackets
{
	if(opening == '(' && closing == ')') 
		return true; //if both are same i.e. (), return true
	else if(opening == '{' && closing == '}') 
		return true; //if both are same i.e. {}, return true
	else if(opening == '[' && closing == ']') 
		return true; //if both are same i.e. [], return true
	return false; //if not same, then return false
}
bool AreParanthesesBalanced(string exp) //to check the expression
{
	stack<char> S; //using stack library and making char type object
	
	for(int i =0;i<exp.length();i++) //using loop that goes till length and pops all the brackets
	{
		if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[') //if using the starting bracket
			S.push(exp[i]); //push fucntion from builtin library
		else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']') //else if using the ending bracket
		{
			if(S.empty() || !ArePair(S.top(),exp[i])) //if stack is empty or the brackets dont match
				return false; //then return false
			else
				S.pop(); //else pop them using fucntion from builtin library
		}
	}
	
	return S.empty() ? true : false; //using ternary operator. If the stack is empty, return true or else return false
}

int main()
{
	string expression; //initializing string variable
	cout<<"Enter an expression:  "; 
	cin>>expression; //input from user
	if(AreParanthesesBalanced(expression)) //calling fucntion to check if they are same
		cout<<endl<<"Success!"<<endl; //print Success if they are the same
	else
		cout<<"Length is: "<<expression.length(); //else print length if not same
}
