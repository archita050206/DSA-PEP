struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = nullptrptr;
    }

};


/* Should return true if linked list is circular, else false */
class Solution {
  public:
    bool isCircular(Node *head) {
        // Your code here
        if(!head)return false;
        Node *temp=head->next;
        while(temp && temp !=head){
            temp=temp->next;
        }
        return temp==head;
    }
};