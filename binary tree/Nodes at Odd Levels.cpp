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
    vector<int> nodesAtOddLevels(Node *root) {
        // code here
        
        vector<int>v;
        if(!root)return v;
        int cnt=1;
        queue<Node *>q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                Node *node=q.front();
                q.pop();
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
                if((cnt%2)!=0)v.push_back(node->data);
                
            }
            cnt++;
        }
        return v;
    }
};