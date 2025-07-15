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
    vector<int> largestValues(Node* root) {
      
       
        vector<int>ans;
         if(!root)return ans;
        queue<Node *>q;
        q.push(root);
        while(!q.empty()){
            int maxi=0;
            int size=q.size();
            for(int i=0;i<size;i++){
                Node *node=q.front();
                q.pop();
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
                maxi=max(maxi,node->data);
            }
            ans.push_back(maxi);
            
        }
        return ans;
    }
};