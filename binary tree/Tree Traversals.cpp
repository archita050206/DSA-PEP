#include<vector>
#include<queue>

using namespace std;
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

void inorder(TreeNode * root, vector<int>&v1){
    if(!root)return;
    inorder(root->left,v1);
    v1.push_back(root->data);
    inorder(root->right,v1);

}
void preorder(TreeNode * root, vector<int>&v2){
    if(!root)return;
    
    v2.push_back(root->data);
    preorder(root->left,v2);
    preorder(root->right,v2);

}
void postorder(TreeNode * root, vector<int>&v3){
    if(!root)return;
    postorder(root->left,v3);
    
    postorder(root->right,v3);
    v3.push_back(root->data);

}
vector<vector<int>> getTreeTraversal(TreeNode *root){
    vector<vector<int>>ans;
    vector<int>v1,v2,v3;
    inorder(root,v1);
    preorder(root,v2);
    postorder(root,v3);
    ans.push_back(v1);
        ans.push_back(v2);

    ans.push_back(v3);
    return ans;

}