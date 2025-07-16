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

    void solver(TreeNode* root, vector<int>&ans){
        if(!root)return;
        if(!root->left && ! root->right){
            ans.push_back(root->val);
            return;
        }
        solver(root->left,ans);
        solver(root->right,ans);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>v1,v2;
        solver(root1,v1);
        solver(root2,v2);
        if(v1.size()!=v2.size())return false;
        for(int i=0;i<v1.size();i++){
            if(v1[i]!=v2[i]){
                return false;
            }
        }
        return true;
    }
};