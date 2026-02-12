
class Node {
    public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

class Solution {
  public:
    Node* deleteNode(Node* head, int key) {
        // code here
        if(!head)return nullptr;
        if(!head->next){
            if(head->data==key){
                
                delete head;
                return nullptr;
            }
            else return head;
            
        }
        if(head->data==key){
            Node *temp=head;
            while(temp->next!=head){
                temp=temp->next;
            }
            Node *t=head;
            head=head->next;
            temp->next=head;
            delete t;
            return head;
        }
        Node *slow=head,*fast=head->next;
        while(fast!=head ){
        
            if(fast->data==key){
                slow->next=fast->next;
                delete fast;
                return head;
            }
            fast=fast->next;
            slow=slow->next;
        }
        
    }
};