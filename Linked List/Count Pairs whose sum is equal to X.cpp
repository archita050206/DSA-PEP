#include<map>
using namespace std;

// store the elements of first ll in the map, and then iterate over the elements of the second map , get the remainder and search if the remainder is in the map

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = nullptr ;
    }
};


class Solution {
  public:
    int countPairs(struct Node* head1, struct Node* head2, int x) {
        int cnt=0;
        Node *f=head1, *s=head2;
        map<int,int>mp;
        while(f){
            mp[f->data]++;
            f=f->next;
        }
        while(s){
            int rem=x-s->data;
            if(mp.count(rem)){
                cnt+=1;
            }
            s=s->next;
            
        }
        return cnt;
    }
};