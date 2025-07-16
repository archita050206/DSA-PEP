#include<vector>
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
  
  void solver(Node *root,vector<int>&ans , int lvl){
      if(!root)return;
      if(ans.size()==lvl)ans.push_back(root->data);
      solver(root->left,ans,lvl+1);
      solver(root->right,ans,lvl+1);
  }
    vector<int> leftView(Node *root) {
        // code here
        // vector<int>v;
        // if(!root)return v;
        // queue<Node *>q;
        // q.push(root);
        // while(!q.empty()){
        //     int size=q.size();
        //     for(int i=0;i<size;i++){
        //         Node *node=q.front();
        //         q.pop();
        //         if(i==0)v.push_back(node->data);
        //         if(node->left)q.push(node->left);
        //         if(node->right)q.push(node->right);
                
        //     }
        // }
        // return v;
        
        vector<int>ans;
        solver(root,ans,0);
        return ans;
        
    }
};