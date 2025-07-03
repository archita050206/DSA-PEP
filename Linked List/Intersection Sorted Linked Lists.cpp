

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=nullptr;
    }
};



class Solution {
  public:
    Node* findIntersection(Node* head1, Node* head2) {
        if(!head1 || !head2)return nullptr;
        Node *i=head1, *j=head2;
        Node *head=new Node(0);
        Node *third=head;
        while(i && j){
            if(i->data==j->data){
                third->next=new Node(i->data);
                third=third->next;
                i=i->next;
                j=j->next;
            }
            else if(i->data<j->data){
                i=i->next;
            }
            else j=j->next;
        }
        
        return head->next;

    }
};