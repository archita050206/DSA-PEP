#include<queue>
#include<cmath>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
  public:
  
  
    bool isPerfect(Node *root) {
        
        if(!root)return false;
        queue<Node *>q;
        int lvl=0;
        q.push(root);
        bool flag=true;
        while(!q.empty()){
            int size=q.size();
            if(size!=pow(2,lvl)){
                return false;
                
            }
            for(int i=0;i<size;i++){
                Node *node=q.front();
                q.pop();
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
                
            }
            lvl++;
        }
        return true;
    }
};