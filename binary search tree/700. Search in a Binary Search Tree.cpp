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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root)return nullptr;
        if(root->val==val)return root;
        if(val<root->val){
        root=searchBST(root->left,val);
        }
        else{
        root=searchBST(root->right, val);
        }
        return root;
    }
};