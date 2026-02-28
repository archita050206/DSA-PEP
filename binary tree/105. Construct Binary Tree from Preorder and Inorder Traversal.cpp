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
    TreeNode *solver(vector<int>&preorder,vector<int>&inorder,int &preorderIdx, int inorderSt,int inorderEnd, int n, unordered_map<int,int>&mp){
        if((preorderIdx>=n)||(inorderSt>inorderEnd))return nullptr;
        int val=preorder[preorderIdx];
        TreeNode *node=new TreeNode(preorder[preorderIdx++]);
        node->left=solver(preorder,inorder,preorderIdx,inorderSt,mp[val]-1,n,mp);
        node->right=solver(preorder, inorder,preorderIdx,mp[val]+1,inorderEnd,n,mp);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>mp;
        int n=preorder.size();
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
        int index=0;
        TreeNode *root=solver(preorder,inorder,index,0,n-1,n,mp);
        return root;
    }
};