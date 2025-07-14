#include<vector>
using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptrptr), right(nullptrptr) {}
     TreeNode(int x) : val(x), left(nullptrptr), right(nullptrptr) {}    
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:
    void solver(TreeNode *root,  vector<int>&ans){
        if(!root)return;
        solver(root->left,ans);
        solver(root->right,ans);
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        solver(root,ans);
        return ans;
    }
};