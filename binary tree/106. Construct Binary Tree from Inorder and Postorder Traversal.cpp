#include<vector>
#include<unordered_map>

using namespace std;
 // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
public:
    TreeNode *solver(vector<int>& inorder, vector<int>& postorder,int &postorderIdx,int inorderSt,int inorderEnd,int n, unordered_map<int,int>&mp ){
        if(postorderIdx<0 || inorderSt>inorderEnd)return nullptr;
        int val=mp[postorder[postorderIdx]];
        TreeNode *node=new TreeNode(postorder[postorderIdx--]);
        node->right=solver(inorder,postorder,postorderIdx,val+1,inorderEnd,n,mp);
        node->left=solver(inorder,postorder,postorderIdx, inorderSt,val-1,n,mp);
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
        int idx=n-1;
        TreeNode *root=solver(inorder,postorder,idx,0,n-1,n,mp);
        return root;
    }
};