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
    int minValue(Node* root) {
        // Iterative approach
        // if(!root)return -1;
        // while(root->left){
        //     root=root->left;
        // }
        // return root->data;
        
        // Recursive approach
        if(!root->left)return root->data;
        return minValue(root->left);
    }
};