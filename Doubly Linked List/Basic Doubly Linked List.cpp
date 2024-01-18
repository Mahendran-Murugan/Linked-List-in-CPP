#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insertHead(Node *&head, int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    head->prev = temp;
    head = temp;
    cout << "Inserted Head Successfully.." << endl;
}

void printFun(Node *head)
{
    if (head == NULL)
    {
        cout << "The Linked List is Empty" << endl;
        return;
    }
    else
    {
        while (head != NULL)
        {
            cout << head->data << '\t';
            head = head->next;
        }
        cout << endl;
    }
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    Node *node1 = new Node(15);
    head = node1;
    tail = node1;
    insertHead(head, 5);
    printFun(head);
    return 0;
}