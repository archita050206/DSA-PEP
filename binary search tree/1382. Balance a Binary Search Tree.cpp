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
    TreeNode *solver(vector<int> v, int l, int h)
    {
        if (l > h)
            return nullptr;
        int mid = (l + h) / 2;
        TreeNode *node = new TreeNode(v[mid]);
        node->left = solver(v, l, mid - 1);
        node->right = solver(v, mid + 1, h);
        return node;
    }
    TreeNode *balanceBST(TreeNode *root)
    {
        if (!root)
            return nullptr;
        vector<int> v;
        inorder(root, v);
        root = solver(v, 0, v.size() - 1);
        return root;
    }
};