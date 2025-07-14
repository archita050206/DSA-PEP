
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr ) {} };
 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head)return false;
        // map<ListNode*, bool> mp;
        // ListNode * t=head;
        // while(t){
        //     if(mp.count(t))return true;
        //     mp[t]=true;
        //     t=t->next;
        // }
        // return false;

        ListNode *fast=head;
        ListNode *slow=head;
        bool b=false;
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow){
                b=true;
                break;
            }
        }
        return b;
        

    }
};