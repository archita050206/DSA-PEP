// a Node of the doubly linked list
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
}; 

class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        // code here
        if(!*head_ref)return ;
        Node *temp=*head_ref;
        while(temp){
            if(temp==*head_ref && temp->data==x){
                *head_ref=temp->next;
                if(*head_ref)(*head_ref)->prev=nullptr;
                Node *t=temp;
                temp=temp->next;
                
                
                delete t;
            }
            else if(temp->data==x){
                Node *t=temp;
                temp=temp->next;
                t->prev->next=t->next;
                if(t->next)
                t->next->prev=t->prev;
                delete t;
            }
            else temp=temp->next;
        }
        
        
    }
};