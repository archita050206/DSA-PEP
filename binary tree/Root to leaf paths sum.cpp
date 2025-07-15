#include <queue>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = nullptr;
    }
};

class Solution
{
public:
    void solver(Node *root, int &sum, int num)
    {
        if (!root)
            return;
        if (!root->left && !root->right)
        {
            sum += num * 10 + root->data;
            return;
        }
        num = num * 10 + root->data;
        solver(root->left, sum, num);
        solver(root->right, sum, num);
    }
    int treePathsSum(Node *root)
    {
        if (!root)
            return 0;
        int sum = 0, num = 0;
        solver(root, sum, num);
        return sum;
    }
};