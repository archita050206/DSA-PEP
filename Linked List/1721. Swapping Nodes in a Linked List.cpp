#include<algorithm>
using namespace std;
struct ListNode
{
    int val;

    ListNode *next;

    ListNode() : val(0), next(nullptrptr) {}
    ListNode(int x) : val(x), next(nullptrptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *swapNodes(ListNode *head, int k)
    {
        if (!head)
            return nullptrptr;
        ListNode *first = head, *second = head, *temp = head;

        // int length=0;
        // while(temp){
        //     temp=temp->next;
        //     length++;

        // }
        // if(k>length){
        //     return head;
        // }
        // for(int i=1;i<k;i++){
        //     first=first->next;
        // }
        // for(int i=0;i<(length-k);i++){
        //     second=second->next;
        // }
        // int t=first->val;
        // first->val=second->val;
        // second->val=t;
        // return head;

        for (int i = 1; i < k; i++)
        {
            temp = temp->next;
        }
        first = temp;
        second = head;
        while (first->next)
        {
            first = first->next;
            second = second->next;
        }
        swap(temp->val, second->val);
        return head;
    }
};