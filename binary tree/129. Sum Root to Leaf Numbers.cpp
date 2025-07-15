
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

    void solver(TreeNode *root, int &sum, int num){
        if(!root)return;
        if(!root->left && !root->right){
            num=num*10+root->val;
            sum+=num;
            return;
        }
        num=10*num+root->val;
        solver(root->left, sum, num);
        solver(root->right, sum,num);

    }
    int sumNumbers(TreeNode* root) {
        int sum=0;
        int num=0;
        solver(root,sum,num);
        return sum;
    }
};