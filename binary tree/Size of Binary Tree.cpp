

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = nullptr;
    }
};


class Solution {
  public:
    int getSize(Node* root) {
        // code here
        if(!root)return 0;
        int left=getSize(root->left);
        int right=getSize(root->right);
        return 1+left+right;
    }
};