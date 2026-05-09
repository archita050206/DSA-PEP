#include<queue>
#include<cmath>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *next;

    Node(int x)
    {
        data = x;
        left = nullptr;
        right = nullptr;
        next =  nullptr;
    }
};

class Solution {
  public:
    void solver(Node *root, vector<Node *>&ans){
        if(!root)return;
        solver(root->left,ans);
        ans.push_back(root);
        solver(root->right, ans);
    }
    void populateNext(Node *root) {
        // code here
        vector<Node *>ans;
        solver(root, ans);
        int n= ans.size();
        for(int i=0;i<n;i++){
            if(i==(n-1))ans[i]->next=nullptr;
            else ans[i]->next=ans[i+1];
        }
    }
};