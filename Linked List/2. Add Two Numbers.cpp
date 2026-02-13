
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy=new ListNode(0);
        ListNode *p=l1,*q=l2,*tail=dummy;
        int sum=0,carry=0;
        while(p||q||carry){
            int v1=(p)?p->val:0;
            int v2=(q)?q->val:0;
            sum=v1+v2+carry;
            carry=sum/10;
            int d=sum%10;
            ListNode *n=new ListNode(d);
            tail->next=n;
            tail=n;
            if(p)p=p->next;
            if(q)q=q->next;
        }
        return dummy->next;
    }
};