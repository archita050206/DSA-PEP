#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val)
    {
        data = val;
        next = prev = nullptr;
    }
};
class Doubly
{   public:
    Node *head, *tail;
    Doubly()
    {
        head = nullptr;
        tail = nullptr;
    }
    void insertAtTail(int val)
    {
        Node *n = new Node(val);
        if (!head)
        {
            head = n;
            tail = n;
            return;
        }
        n->prev = tail;
        tail->next = n;
        tail = n;
    }
    void insertAtHead(int val)
    {
        Node *n = new Node(val);
        if (!head)
        {
            head = n;
            tail = n;
            return;
        }
        n->next = head;
        head->prev = n;
        head = n;
    }
    void printList()
    {
        Node *t = head;
        Node *p = tail;
        cout << "Forward: " << endl;
        while (t)
        {
            cout << t->data << ' ';
            t = t->next;
        }
        cout << endl;
        cout << "Backward: " << endl;
        while (p)
        {
            cout << p->data << ' ';
            p = p->prev;
        }
    }
};
int main(){
    Doubly d;
    d.insertAtHead(2);
    d.insertAtTail(3);
    d.insertAtHead(1);
    d.insertAtTail(4);
    d.printList();

}