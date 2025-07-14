
    
    class Node {
        public :

        int data;
        Node *next;

        Node(int data) {
            this -> data = data;
            this -> next = nullptr ;
        }
    };

#include<map>
using namespace std;
Node *removeLoop(Node *head)
{
    //TC = O(n)
    //SC= O(n)
    // create a map, check if the next node is present in the map, if yes then make it to nullptr . If no then add that node itself to the map

    // if(!head)return nullptr ;
    // map<Node*, bool>mp;
    // Node *t=head;
    // while(t->next){
    //     if(mp.count(t->next)){
    //         t->next=nullptr ;
    //         break;
    //     }
    //     else mp[t]=true;
    //     t=t->next;
    // }
    // return head;

    //TC = O(n)
    //SC = O(1)

   Node *fast=head,*slow=head;
   while(fast && fast->next){
       fast=fast->next->next;
       slow=slow->next;
       if(fast==slow){
           slow=head;
           while(slow!=fast){
               fast=fast->next;
               slow=slow->next;
           }
           Node *t=slow;
        while(t && t->next!=slow){
        t=t->next;
    }
    if(t->next)t->next=nullptr ;
    break;
    
           
       }
   }
   return head;
   
}