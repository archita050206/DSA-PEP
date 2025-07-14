
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr ) {}
    ListNode(int x) : val(x), next(nullptr ) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        if (!head)
            return nullptr ;
        // int cnt=0;
        // ListNode *t=head;
        // while(t){
        //     cnt++;
        //     t=t->next;
        // }
        // cnt=cnt/2;
        // t=head;
        // for(int i=0;i<cnt;i++){
        //     t=t->next;
        // }
        // return t;
        ListNode *f = head;
        ListNode *s = head;
        while (f && f->next)
        {
            s = s->next;
            f = f->next->next;
        }
        return s;
    }
};