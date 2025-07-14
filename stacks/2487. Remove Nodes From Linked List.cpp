#include<stack>
#include<algorithm>
#include<string>

using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptrptr) {}
      ListNode(int x) : val(x), next(nullptrptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:


    // ListNode* insertAtHead(ListNode* node, ListNode*head){
      
    //     if(!head){
    //         head=node;
    //         return head;
    //     }
    //     node->next=head;
    //     head=node;
    //     return head;

    // }
    ListNode* removeNodes(ListNode* head) {
        if(!head || !head->next)return head;
        stack<ListNode*>st;
        ListNode* t=head;
        while(t){
           
          if(!st.empty() && (st.top()->val < t->val)){
            st.pop();
          }
          else{
            st.push(t);
          
          t=t->next;
          }
        }
        ListNode* h=nullptrptr;
        while(!st.empty()){
            // ListNode* v=st.top();
            // st.pop();
            // h=insertAtHead(v,h);
            t=st.top();
            st.pop();
            t->next=h;
            h=t;

        }
        return h;
        
    }
};