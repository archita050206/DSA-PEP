#include<vector>
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
    bool check(TreeNode *p, TreeNode *q){
        if(!p && !q)return true;
        if(!p || !q)return false;
        if(p->val!=q->val)return false;
        return check(p->left, q->right) && check(p->right,q->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root)return true;
        TreeNode *p=root->left;
        TreeNode *q=root->right;
        return check(p,q);

    }
};