// Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        Node *o=new Node(1);
        Node *ot=o;
        Node *z=new Node(0);
        Node *zt=z;
        Node *t=new Node(2);
        Node *tt=t;
        Node *temp=head;
        while(temp){
            if(temp->data==0){
                zt->next=temp;
                temp=temp->next;
                zt=zt->next;
                zt->next=nullptr;
            }
            else if(temp->data==1){
                ot->next=temp;
                temp=temp->next;
                ot=ot->next;
                ot->next=nullptr;
            }
            else if(temp->data==2){
                tt->next=temp;
                temp=temp->next;
                tt=tt->next;
                tt->next=nullptr;
            }
        }
        if(z->next){
            zt->next=(o->next)?o->next:t->next;
        }
        else z->next=(o->next)?o->next:t->next;
        if(o->next){
            ot->next=t->next;
        }
        return z->next;
    }
};