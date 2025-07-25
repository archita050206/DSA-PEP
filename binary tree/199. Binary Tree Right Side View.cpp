#include<vector>
#include<stack>

using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr ), right(nullptr ) {}
     TreeNode(int x) : val(x), left(nullptr ), right(nullptr ) {}    
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:

    void solver(TreeNode* root,vector<int>&ans, int lvl ){
        if(!root)return;
        if(lvl==ans.size()){
            ans.push_back(root->val);

        }
        solver(root->right,ans,lvl+1);
        solver(root->left,ans,lvl+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int>ans;
        if(!root)return ans;
        solver(root,ans,0);
        return ans;
    }
};