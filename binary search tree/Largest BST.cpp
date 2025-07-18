#include <climits>
#include <algorithm>

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
    bool isValid(Node *root, long long l, long long h)
    {
        if (!root)
            return true;
        if (root->data >= h || root->data <= l)
            return false;
        return isValid(root->left, l, root->data) && isValid(root->right, root->data, h);
    }
    int cnt(Node *root)
    {
        if (!root)
            return 0;

        return 1 + cnt(root->left) + cnt(root->right);
    }
    int largestBst(Node *root)
    {
        // Your code here
        if (isValid(root, LLONG_MIN, LLONG_MAX))
        {
            return cnt(root);
        }
        return max(largestBst(root->left), largestBst(root->right));
    }
};