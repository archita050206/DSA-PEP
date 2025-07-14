/**
 * Definition for singly-linked list.
 *  */
  struct ListNode {
      int val;
      ListNode *next;
     ListNode() : val(0), next(nullptrptr) {}
      ListNode(int x) : val(x), next(nullptrptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
     ListNode* rev(ListNode * head, ListNode *prev){
        if(!head)return prev;
        ListNode* forward=head->next;
        head->next=prev;
        return rev(forward,head);

    }
    ListNode* reverseList(ListNode* head) {
        // if(!head)return nullptrptr;
        // if(head && !head->next)return head;
        // ListNode* prev=nullptrptr;
        // ListNode* curr=head;
        
        // ListNode* forward=nullptrptr;
        // while(curr){
        //     forward=curr->next;
        //     curr->next=prev;
        //     prev=curr;
        //     curr=forward;
        // }
        // return prev;
       
        ListNode * ans=rev(head,nullptrptr);
        return ans;
    }
};