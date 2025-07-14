
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

class Solution
{
public:

    // Total number of nodes - Number of leaf nodes

    //   int countLeaf(Node *root){
    //       if(!root)return 0;
    //       if(!root->left && !root->right)return 1;
    //       return countLeaf(root->left)+countLeaf(root->right);
    //   }
    //   int countTotal(Node *root){
    //       if(!root)return 0;
    //       return 1+countTotal(root->left)+countTotal(root->right);
    //   }

    int countNonLeafNodes(Node *root)
    {
        
        // return countTotal(root)-countLeaf(root);
        if (!root || (!root->left && !root->right))
            return 0;
        return 1 + countNonLeafNodes(root->left) + countNonLeafNodes(root->right);
    }
};