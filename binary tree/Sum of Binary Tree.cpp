
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
    int sumBT(Node* root) {
        
        if(!root)return 0;
        return root->data+sumBT(root->left)+sumBT(root->right);
    }
};