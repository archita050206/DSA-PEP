
  //Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(!head)return nullptr;
        ListNode *curr=head,*sorted=nullptr;
        while(curr){
            ListNode *next=curr->next;
            if(!sorted || curr->val<sorted->val){
                curr->next=sorted;
                sorted=curr;
            }
            else{
                ListNode *temp=sorted;
                while(temp->next && temp->next->val<curr->val){
                    temp=temp->next;
                }
                curr->next=temp->next;
                temp->next=curr;
            }
            curr=next;
        }
        return sorted;
    }
};