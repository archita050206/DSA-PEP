#include<queue>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

class Solution
{
public:

    int isSumProperty(Node *root) {
        
        if(!root)return 0;
        queue<Node *>q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                Node *node=q.front();
                q.pop();
                int sum=0;
                if(node->left){
                    sum+=node->left->data;
                    q.push(node->left);
                }
                if(node->right){
                    sum+=node->right->data;
                    q.push(node->right);
                }
                else if(!node->left && !node->right)sum=node->data;
                if(sum!=node->data)return 0;
            }
        }
        return 1;
    }
};