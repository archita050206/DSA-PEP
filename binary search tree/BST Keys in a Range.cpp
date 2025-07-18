#include <vector>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
        : data(val), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    void solver(Node *root, int l, int h, vector<int> &ans)
    {
        if (!root)
            return;
        solver(root->left, l, h, ans);
        if (root->data >= l && root->data <= h)
        {
            ans.push_back(root->data);
        }
        solver(root->right, l, h, ans);
    }
    vector<int> printNearNodes(Node *root, int low, int high)
    {
        
        vector<int> ans;
        if (!root)
            return ans;
        solver(root, low, high, ans);
        return ans;
    }
};