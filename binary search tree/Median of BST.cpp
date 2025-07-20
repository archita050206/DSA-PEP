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
    void inorder(struct Node* root, vector<float>&v){
    if(!root)return;
    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}
float findMedian(struct Node *root) {
    // Code here
    if(!root)return -1;
    vector<float>v;
    inorder(root,v);
    int n=v.size();
    int half=n/2;
    if(n%2==0){
        
        return (v[half]+v[half-1])/2.0;
    }
    
        return v[half];
    
}
};