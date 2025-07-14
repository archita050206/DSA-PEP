#include<map>
#include<iostream>
using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptrptr) {}
  };
 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head ||!head->next)return nullptrptr;

        map<ListNode *, bool>mp;
        ListNode * t=head;
        while(t){
            if(mp.count(t))return t;
            mp[t]=true;
            t=t->next;
        }
        return nullptrptr;

        // ListNode* fast=head;
        // ListNode* slow=head;
        // while(fast && fast->next){
            
        //     slow=slow->next;
        //     fast=fast->next->next;
        //     if(slow==fast){
        //         slow=head;
        //         while(slow!=fast){

        //             slow=slow->next;
        //             fast=fast->next;
        //         }
        //         return slow;
        //     }
        // }
        // return nullptrptr;

    }
};