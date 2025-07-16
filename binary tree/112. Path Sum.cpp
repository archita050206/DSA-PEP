
#include<vector>
#include<cmath>

using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr ) {}    
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:
    bool solver(TreeNode* root,int sum, int targetSum){
        if(!root)return false;
        sum+=root->val;
        if(!root->left && !root->right){
            if(sum==targetSum)return true;
            
        }
        return solver(root->left,sum,targetSum)||solver(root->right,sum,targetSum);

    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)return false;
        int sum=0;
        bool b=solver(root,sum,targetSum);
        return b;

    }
};