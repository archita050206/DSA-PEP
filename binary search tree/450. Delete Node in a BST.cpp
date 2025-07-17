#include<vector>
#include<queue>
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
     TreeNode *maxVal(TreeNode *root){
        while(root && root->right){
            root=root->right;
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)return nullptr;
        if(key<root->val){
            root->left=deleteNode(root->left,key);
        }
        if(key>root->val){
            root->right=deleteNode(root->right,key);
        }
        if(root->val==key){
            if(!root->left && !root->right){
                delete root;
                return nullptr;
            }
            else if((!root->left && root->right) ){
                TreeNode *temp=root->right;
                delete root;
                return temp;
            }
            else if((!root->right && root->left)){
                TreeNode * temp=root->left;
                delete root;
                return temp;
            }
            else{
                TreeNode *node= maxVal(root->left);
                root->val=node->val;
                root->left=deleteNode(root->left,root->val);
            }
        }
        return root;
    }
};