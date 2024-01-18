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

void insertTail(Node *&tail, int data)
{
    Node *temp = new Node(data);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
    cout << "Inserted Tail Successfully.." << endl;
}

void insertIntoPosition(Node *&head, Node *&tail, int position, int data)
{
    if (position == 1)
    {
        insertHead(head, data);
        return;
    }
    Node *temp = head;
    int count = 1;
    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }
    if ((temp->next)->next == NULL)
    {
        insertTail(tail, data);
        return;
    }
    Node *newNode = new Node(data);
    newNode->prev = temp;
    newNode->next = temp->next;
    (temp->next)->prev = newNode;
    temp->next = newNode;
    cout << "Inserted at " << position << " Position Successfully.." << endl;
}

void deleteHead(Node *&head)
{
    (head->next)->prev = NULL;
    head = head->next;
    cout << "Deleted Head Successfully.." << endl;
}

void deleteTail(Node *&tail)
{
    (tail->prev)->next = NULL;
    tail = tail->prev;
    cout << "Deleted Tail Successfully.." << endl;
}

void deleteIntoPosition(Node *&head, Node *&tail, int position)
{
    if (position == 1)
    {
        deleteHead(head);
        return;
    }
    Node *temp = head;
    int count = 1;
    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }
    if ((temp->next)->next == NULL)
    {
        deleteTail(tail);
        return;
    }
    temp->next = (temp->next)->next;
    ((temp->next)->next)->prev = temp;
    cout << "Deleted Tail Successfully.." << endl;
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
    insertTail(tail, 20);
    printFun(head);
    insertIntoPosition(head, tail, 2, 10);
    printFun(head);
    deleteHead(head);
    printFun(head);
    deleteTail(tail);
    deleteIntoPosition(head, tail, 4);
    printFun(head);
    return 0;
}