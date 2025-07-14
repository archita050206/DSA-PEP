#include <unordered_map>
using namespace std;
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = nullptrptr;
  }
};


class Solution {
  public:
    Node *removeDuplicates(Node *head) {
        if(!head||!head->next)return head;
        unordered_map<int,bool>mp;
        Node *curr=head,*prev=nullptrptr;
        while(curr){
            if(mp.count(curr->data)){
                prev->next=curr->next;
                Node *t=curr;
                
                delete t;
                curr=prev->next;
            }
            else{
                mp[curr->data]=true;
                prev=curr;
                curr=curr->next;
            }
            
        }
        return head;
    }
};