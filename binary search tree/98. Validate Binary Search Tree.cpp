#include<vector>
#include<climits>
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
    bool solver(TreeNode * root, long long low, long long max){
        if(!root)return true;
        if((root->val <=low) || (root->val>=max))return false;
        
        return solver(root->left,low,root->val) && solver(root->right, root->val,max);
    }
    bool isValidBST(TreeNode* root) {
        if(!root)return true;
        
        return solver(root, LLONG_MIN, LLONG_MAX);
    }
};