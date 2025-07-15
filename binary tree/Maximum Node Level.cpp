#include<vector>
#include<queue>

using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = nullptr ;
    }
};


class Solution {
  public:
     int maxNodeLevel(Node *root) {
        
        if(!root)return -1;
        int maxi=0,lvl=0,cnt=0;
        queue<Node *>q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            if(size>maxi){
                maxi=size;
                lvl=cnt;
            }
            for(int i=0;i<size;i++){
                Node *node=q.front();
                q.pop();
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
                
            }
            cnt++;
                
        }
        return lvl;
    }
};