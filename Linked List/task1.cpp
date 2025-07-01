#include<iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = nullptr;
    }
};
class MyLinkedList
{
public:
    Node *head;
    MyLinkedList()
    {
        head = nullptr;
    }

    
    void insert(int val)
    {
        Node *n = new Node(val);
        if (!head)
        {
            head = n;
            return;
        }
       Node *t=head;
        while(t->next){
            t=t->next;
        }
        t->next=n;
    }

    void update(int s, int g){
        if(!head)return;
        Node *t=head;
        while(t){
            if(t->data==s){
                t->data=g;
                break;
            }
            t=t->next;
        }
    }

    int length(){

        if(!head)return 0;
        int cnt=0;
        Node *t=head;
        while(t){
            cnt++;
            t=t->next;
        }
        return cnt;
    }

    int indexOfLast(int val){
        if(!head)return -1;
        Node *t=head;
        int index=-1,cnt=-1;
        while(t){
            cnt++;
            if(t->data==val){
                index=cnt;
            }
            t=t->next;
        }
        return index;
    }
   void print(){
    if(!head)return;
    Node *t=head;
    while(t){
        cout<<t->data<<' ';
        t=t->next;
    }
   }
    

    
};
int main(){
    MyLinkedList ll;
    ll.insert(9);
    ll.insert(10);
    ll.insert(12);
    ll.insert(3);
    ll.insert(5);
    ll.insert(9);
    ll.insert(8);
    ll.insert(4);
    ll.insert(5);
    ll.insert(1);
   ll.print();
   cout<<endl;
   ll.update(5,15);
   ll.print();
      cout<<endl;

   int last=ll.indexOfLast(9);
   cout<<last;
      cout<<endl;

   int length=ll.length();
   cout<<length;
    
}
