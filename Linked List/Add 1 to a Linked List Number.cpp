

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = nullptr;
    }
};



class Solution {
  public:
    Node *reverseLL(Node *head){
        Node *prev=nullptr,*curr=head,*forw=nullptr;
        while(curr){
            forw=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forw;
        }
        return prev;
    }
    Node* addOne(Node* head) {
        // Your Code here
        
        // return head of list after adding one
        Node *tail=nullptr;
        Node *newH=reverseLL(head);
        Node *temp=newH;
        int carry=0;
        while(temp){
            tail=temp;
            if(temp==newH){
                int s=temp->data+1;
                carry=s/10;
                s=s%10;
                temp->data=s;
            }
            else{
                if(carry!=0){
                    int s=temp->data+carry;
                    carry=s/10;
                    s=s%10;
                    temp->data=s;
                    
                }
            }
            temp=temp->next;
        }
        if(carry!=0){
            Node *n=new Node(carry);
            tail->next=n;
        }
        newH=reverseLL(newH);
        return newH;
    }
};