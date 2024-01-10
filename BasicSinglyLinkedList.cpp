#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int val, Node *add)
    {
        data = val;
        next = add;
    }
};

void printFun(Node *ptrHead)
{
    if (ptrHead == NULL)
    {
        cout << "The Linked List is Empty";
        return;
    }
    else
        while (ptrHead != NULL)
        {
            cout << ptrHead->data << '\t';
            ptrHead = ptrHead->next;
        }
}

int main()
{
    Node *head;
    Node *one = NULL;
    Node *two = NULL;
    Node *three = NULL;

    three = new Node(3, NULL);
    two = new Node(2, three);
    one = new Node(1, two);

    head = one;

    printFun(head);

    cout << endl;

    return 0;
}