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
        next = prev = nullptr ;
    }
};
class Doubly
{
public:
    Node *head, *tail;
    Doubly()
    {
        head = nullptr ;
        tail = nullptr ;
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

    void insertAtPosition(int val, int index)
    {
        if (index == 0)
            insertAtHead(val);
        int length = 0;
        Node *t = head;
        while (t)
        {
            length++;
            t = t->next;
        }
        if (index == (length))
            insertAtTail(val);
        if (index > (length))
            return;
        Node *n = new Node(val);
        t = head;
        for (int i = 1; i < index; i++)
        {
            t = t->next;
        }
        n->next = t->next;
        n->prev = t;
        t->next->prev = n;
        t->next = n;
    }
    void deleteAtPosition(int x){
         int index=x-1;
        if(!head)return;
        if(index==0){
            
            Node *t=head;
            head=head->next;
            head->prev=nullptr ;
            t->next=nullptr ;
            delete t;
            return;
        }
        int length=0;
        Node *t=head;
        while(t){
            length++;
            t=t->next;
        }
        t=head;
        if(length==x){
            while(t->next){
                t=t->next;
            }
            t->prev->next=nullptr ;
            t->prev=nullptr ;
            delete t;
            return;
            
        }
        t=head;
        for(int i=1;i<index;i++){
            t=t->next;
        }
        Node *n=t->next;
        n->prev=nullptr ;
        t->next=n->next;
        n->next->prev=t;
        n->next=nullptr ;
        delete n;
        return;
    }
};
int main()
{
    Doubly d;
    d.insertAtHead(2);
    d.insertAtTail(3);
    d.insertAtHead(1);
    d.insertAtTail(5);
    d.printList();
    d.insertAtPosition(4, 3);
    d.printList();
}