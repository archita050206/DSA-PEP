
class Node {
 public:
  int data;
  Node *next;

  Node(int x){
      data = x;
      next = nullptr;
  }
}; 

class Solution {
  public:
    Node* sortedInsert(Node* head, int data) {
        // code here
        
        Node *p=new Node(data);
        if(!head)
        {
            p->next=p;
            return p;
        }
       
        if(head->data>data){
           Node *tail=head;
            while(tail->next!=head){
                tail=tail->next;
            }
            
            p->next=head;
            head=p;
          tail->next=head;
          return head;
        }
        Node *temp=head;
        while(temp->next!=head && temp->next->data<data){
           
                temp=temp->next;
            
        }
        p->next=temp->next;
        temp->next=p;
        return head;
    }
};