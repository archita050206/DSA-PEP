
struct Node
{
    int data;
    Node* left;
    Node* right;
}; 


class Solution {
  public:
    // Function to count the number of leaf nodes in a binary tree.
    
    int countLeaves(Node* root) {
        // write code here
        if(!root)return 0;
        if(!root->left && !root->right)return 1;
        int left=countLeaves(root->left);
        int right=countLeaves(root->right);
        return left+right;
        
    }
};