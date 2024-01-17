#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertHead(Node *&head, int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
    cout << "Inserted at Head Successfully.." << endl;
}

void insertTail(Node *&tail, int data)
{
    Node *temp = new Node(data);
    if (tail == NULL)
        cout << "Tail is Empty" << endl;
    else
    {
        tail->next = temp;
        tail = temp;
        cout << "Inserted at Tail Successfully.." << endl;
    }
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
    if (temp->next == NULL)
    {
        insertTail(tail, data);
        return;
    }
    Node *node = new Node(data);
    node->next = temp->next;
    temp->next = node;
    cout << "Inserted at " << position << " Position Successfully.." << endl;
}

void deleteHead(Node *&head)
{
    head = head->next;
    cout << "Head is Deleted.." << endl;
}

void deleteTail(Node *&head, Node *&tail)
{
    Node *temp = head;
    while ((temp->next)->next != NULL)
    {
        temp = temp->next;
    }
    tail = temp;
    temp->next = NULL;
    cout << "Tail is Deleted.." << endl;
}

void deleteIntoPosition(Node *&head, Node *&tail, int Position)
{
    if (Position == 1)
    {
        deleteHead(head);
        return;
    }
    Node *temp = head;
    int count = 1;
    while (count < Position - 1)
    {
        temp = temp->next;
        count++;
    }
    if ((temp->next)->next == NULL)
    {
        deleteTail(head, tail);
        return;
    }
    temp->next = (temp->next)->next;
    cout << "Deleted at " << Position << " Position Successfully.." << endl;
}

void reverseLinkedList(Node *&head, int flag)
{
    string s = "";
    if (flag != 0)
        s = " At specific Index";
    cout << "The Linked List After Reversal" << s << ".." << endl;
    Node *current = head;
    Node *prev = NULL, *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

void printFun(Node *ptrHead)
{
    if (ptrHead == NULL)
    {
        cout << "The Linked List is Empty" << endl;
        return;
    }
    else
    {
        while (ptrHead != NULL)
        {
            cout << ptrHead->data << '\t';
            ptrHead = ptrHead->next;
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
    insertTail(tail, 25);
    printFun(head);
    insertIntoPosition(head, tail, 2, 10);
    printFun(head);
    reverseLinkedList(head, 0);
    printFun(head);
    return 0;
}