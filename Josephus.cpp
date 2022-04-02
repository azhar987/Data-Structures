#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class Josephus {
    public:
    Node* head, *temp, *temp2;
    int val, len;

    Josephus() {
        head = temp = temp2 = NULL;
        val = len = 0;
    }

    bool isEmpty() {
        if (head == NULL) {
            return true;
        }

        else {
            return false;
        }
    }

    void firstNode(int val) {
        if (isEmpty()) {
            head = new Node;
            head -> data = val;
            head -> next = head;
            temp = head;
            len++;
            return;
        }
    }
    void insert(int val) {
        if (isEmpty()) {
            firstNode(val);
            return;
        }

        else {
            temp2 = new Node;
            temp2 -> data = val;
            temp -> next = temp2;
            temp = temp2;
            temp -> next = head;
            len++;
        }
        return;
    }

    void printData() {
        if (isEmpty()) {
            cout << "EMPTY LIST, NOTHING TO PRINT" << endl;
            return;
        }

        else {
            temp = head;

            do {
                cout << temp -> data << " ";
                temp = temp -> next;
            }
            while(temp != head);

            cout << "\nThe Length of List is: " << len << endl;
        }
    }

    int josephusProb(int key) {
        if (isEmpty()) {
            cout << "EMPTY LIST, NO WINNER" << endl;
            return -1;
        }

        else {
            temp = head;
            Node* del = temp -> next;

            while (head -> next != head) {
                for (int i = 1; i < key; i++) {
                    temp = del;
                    del = del -> next;
                }

                temp -> next = del -> next;

                if(del == head) {
                    head = head -> next;
                }

                val = del -> data;
                delete del;
                temp = temp -> next;
                del = temp -> next;

                cout << "[" << val << " out]" << " ";
            }
            cout << endl;
            cout << "THE WINNER IS: ";
            return head -> data;
        }
    }
};

int main() {
    Josephus obj;

    obj.insert(1);
    obj.insert(2);
    obj.insert(3);
    obj.insert(4);
    obj.insert(6);
    obj.insert(7);
    obj.insert(8);
    obj.insert(9);
    obj.insert(10);
    obj.printData();

    cout << endl;

    cout << obj.josephusProb(3);

    return 0;
}