
 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* merged(ListNode *left, ListNode *right){
        ListNode *dummy=new ListNode (-1);
        ListNode *temp=dummy;
        while(left && right){
            if(left->val <=right->val){
                temp->next=left;
                left=left->next;
                temp=temp->next;
            }
            else {
                temp->next=right;
                right=right->next;
                temp=temp->next;

            }
        }
        if(left){
            temp->next=left;
        }
        if(right){
            temp->next=right;
        }
        return dummy->next;
    } 
    ListNode *findMiddle(ListNode *head){
        ListNode *fast=head->next,*slow=head;
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    ListNode* merge(ListNode *head){
        if(!head || !head->next)return head;
        ListNode *middle=findMiddle(head);
        ListNode *leftHead=head;
        ListNode *rightHead=middle->next;
        middle->next=nullptr;
        leftHead=merge(leftHead);
        rightHead=merge(rightHead);
        return merged(leftHead,rightHead);
    }
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)return head;
        return merge(head);
    }
};