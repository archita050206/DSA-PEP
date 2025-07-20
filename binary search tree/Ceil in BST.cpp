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
    void inorder(Node *root, vector<int>&v){
    if(!root)return;
    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}
int findCeil(Node* root, int input) {
    // Your code here
    if(!root)return -1;
    vector<int>v;
    inorder(root,v);
    // for(int i: v){
    //     if(i>=(input))return i;
    // }
    int l=0,h=v.size()-1;
    int ceilval=-1;
    while(l<=h){
        int mid=(l+h)/2;
        if(v[mid]>=input){
            ceilval=v[mid];
            h=mid-1;
        }
        else l=mid+1;
    }
    return ceilval;
    
}
};