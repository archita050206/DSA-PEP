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

class Solution {
  public:
    // Function to find the nodes that are common in both BST.
    void inorder(Node *root, vector<int>&v){
        if(!root)return;
        inorder(root->left,v);
        v.push_back(root->data);
        inorder(root->right,v);
    }
    vector<int> findCommon(Node *r1, Node *r2) {
        // Your code here
        vector<int>v1,v2,v3;
        inorder(r1,v1);
        inorder(r2,v2);
        
        int i=0,j=0;
        while(i<v1.size() && j<v2.size()){
            if(v1[i]<v2[j])i++;
            else if(v1[i]==v2[j])
            {
                v3.push_back(v1[i]);
                i++;
                j++;
            }
            else j++;
        }
        return v3;
    }
};