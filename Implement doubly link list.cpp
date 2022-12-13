#include<iostream>
#include <bits/stdc++.h>
using namespace std;
struct Node
{
int data;
struct Node* next;
struct Node* prev;
};
void insert(struct Node** start, int value)
{
if (*start==NULL)
{
struct Node* new_node = new Node;
new_node->data = value;
new_node->next = new_node->prev = new_node;
*start = new_node;
return;
}
Node* last = (*start)->prev;
struct Node* new_node = new Node;
new_node->data = value;
new_node->next = *start;
(*start)->prev = new_node;
new_node->prev = last;
last->next = new_node;
}
void deleteNode(struct Node** start, int key)
{
if (*start == NULL)
return;
struct Node *curr = *start, *prev_1 = NULL;
while (curr->data != key) {
if (curr->next == *start) {
cout<<"\nList doesn't have node with value = "<<key<<endl;
return;
}
prev_1 = curr;
curr = curr->next;
}
if (curr->next == *start && prev_1 == NULL) {
(*start) = NULL;
free(curr);
return;
}
if (curr == *start) {
prev_1 = (*start)->prev;
*start = (*start)->next;
prev_1->next = *start;
(*start)->prev = prev_1;
free(curr);
}
else if (curr->next == *start) {
prev_1->next = *start;
(*start)->prev = prev_1;
free(curr);
}
else {
struct Node* temp = curr->next;
prev_1->next = temp;
temp->prev = prev_1;
free(curr);
}
}
void display(struct Node* start)
{
struct Node* temp = start;
while (temp->next != start) {
cout<<temp->data;
temp = temp->next;
}
cout<<temp->data;
}
int main()
{
struct Node* start = NULL;
insert(&start, 17);
insert(&start, 94);
insert(&start, 8);
insert(&start, 72);
insert(&start, 25);
cout<<"List Before Deletion: " <<endl;
display(start);
deleteNode(&start, 1);
cout<<"List After Deletion: "<<endl;
display(start);
cout<<endl;
deleteNode(&start, 8);
cout<<"List After Deletion :"<<endl;
display(start);
cout<<endl;
deleteNode(&start, 25);
cout<<"List After Deletion : "<<endl;
display(start);
cout<<endl;
deleteNode(&start, 17);
cout<<"List After Deletion: "<<endl;
display(start);
return 0;
}
