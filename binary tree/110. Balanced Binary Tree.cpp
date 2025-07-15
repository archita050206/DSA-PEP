
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
    int solver(TreeNode *root, bool &flag ){
    if(!root)return 0;
    
    int left=solver(root->left,flag);
    int right=solver(root->right,flag);
    if(abs(left-right)>1)flag=false;
    return 1+max(left,right);
}
    bool isBalanced(TreeNode* root) {
        if(!root)return true;
        bool flag=true;
        solver(root,flag);
        return flag;
        
    }
};