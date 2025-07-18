#include <vector>
#include <climits>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    void inorder(TreeNode *root, vector<int> &v)
    {
        if (!root)
            return;
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }
    void solver(TreeNode *root, int &k, int &ans)
    {
        if (!root)
            return;
        solver(root->left, k, ans);
        k--;
        if (k == 0)
        {
            ans = root->val;
            return;
        }
        solver(root->right, k, ans);
    }
    int kthSmallest(TreeNode *root, int k)
    {
        // vector<int>v;
        // inorder(root,v);
        // return v[k-1];
        if (!root)
            return -1;
        int ans = -1;
        solver(root, k, ans);
        return ans;
    }
};