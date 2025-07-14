#include<queue>
using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = nullptr;
    }
}; 


class Solution {
  public:
    int sumBT(Node* root) {
        
        if(!root)return 0;
        //return root->data+sumBT(root->left)+sumBT(root->right);
        int sum=0;
        queue<Node *>q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                Node *node=q.front();
            q.pop();
            sum+=node->data;
            if(node->left)q.push(node->left);
            if(node->right)q.push(node->right);
            }
            
        }
        return sum;
    }
};