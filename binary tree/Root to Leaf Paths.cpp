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
    void solver(Node* root,vector<int>temp, vector<vector<int>>&ans){
      if(!root)
      {return;}
      if(!root->left && !root->right){
          temp.push_back(root->data);
          ans.push_back(temp);
          temp.pop_back();
          return;
      }
        temp.push_back(root->data);
        solver(root->left,temp,ans);
        solver(root->right,temp,ans);
        
  }
    vector<vector<int>> Paths(Node* root) {
        
        vector<vector<int>>ans;
        if(!root)return ans;
        vector<int>temp;
        solver(root,temp,ans);
        return ans;
    }
};