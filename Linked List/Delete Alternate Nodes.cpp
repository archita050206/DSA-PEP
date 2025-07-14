
struct Node
{
    int data;
    struct Node *next;

    Node(int x){
        int data = x;
        next = nullptrptr;
    }
};

class Solution {
  public:
    void deleteAlt(struct Node *head) {
        if(!head)return;
        // Node *first=head->next, *second=head;
        // while(first){
        //     second->next=first->next;
        //     delete first;
        //     second=second->next;
        //     if(!second || !second->next)break;
        //     first=second->next;
            
        // }
        
        Node *temp=head;
        while(temp && temp->next){
            Node *d=temp->next;
            
            temp->next=temp->next->next;
            
            delete d;
            temp=temp->next;
            
        }
        
    }
};