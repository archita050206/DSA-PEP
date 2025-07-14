#include<vector>
#include<stack>

using namespace std;
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

    //Recursive way
    
    void preorder(TreeNode *root, vector<int>&v){
        if(!root)return;
        v.push_back(root->val);
        preorder(root->left,v);
        preorder(root->right,v);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>v;
        preorder(root,v);
        return v;
    }

    //Iterative way

    // vector<int> preorderTraversal(TreeNode* root) {
    //     vector<int>v;
    //     stack<TreeNode *>st;
    //     if(!root)return v;
    //     st.push(root);
    //     while(!st.empty()){
    //         TreeNode *node=st.top();
    //         st.pop();
    //         if(node->right)st.push(node->right);
    //         if(node->left)st.push(node->left);
    //         v.push_back(node->val);
    //     }
    //     return v;
    // }
};