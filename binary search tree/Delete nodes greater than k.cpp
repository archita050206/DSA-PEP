#include <vector>
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
    Node *create(vector<int> &v, int l, int h)
    {
        if (l > h)
            return nullptr;
        int mid = (l + h) / 2;
        Node *node = new Node(v[mid]);
        node->left = create(v, l, mid - 1);
        node->right = create(v, mid + 1, h);
        return node;
    }
    void inorder(Node *root, vector<int> &v, int k)
    {
        if (!root)
            return;
        inorder(root->left, v, k);
        if (root->data < k)
            v.push_back(root->data);
        inorder(root->right, v, k);
    }
    Node *deleteNode(Node *root, int k)
    {
        
        if (!root)
            return nullptr;
        vector<int> v;
        inorder(root, v, k);

        Node *newroot = create(v, 0, v.size() - 1);
        return newroot;
    }
};