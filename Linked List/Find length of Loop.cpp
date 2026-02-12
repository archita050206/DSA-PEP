
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};


class Solution {
  public:
    int lengthOfLoop(Node *head) {
        // code here
        if(!head ||!head->next)return 0;
        
        Node *f=head,*s=head,*temp=head;
        int total=0,cnt=0;
        
        while(f && f->next){
            s=s->next;
            f=f->next->next;
            if(s==f){
                s=head;
                while(s!=f){
                    s=s->next;
                    f=f->next;
                }
                break;
            }
        }
        if(s!=f)return 0;
        temp=s;
        do{
            temp=temp->next;
            cnt++;
        }while(temp!=s);
        
        return cnt;
    }
};