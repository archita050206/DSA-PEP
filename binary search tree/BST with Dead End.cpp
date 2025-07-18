#include<vector>
#include<set>

using namespace std;
class Node
{
    public:
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
  public:
  
  bool solver(Node *root, int l, int h){
      if(!root)return false;
      if((l==root->data) && (h==root->data)){
          return true;
          
      }
      
      return solver(root->left,l,root->data-1) || solver(root->right,root->data+1,h);
  }
  
  void inorder(Node *root, set<int>&v){
      if(!root)return;
      inorder(root->left,v);
      v.insert(root->data);
      inorder(root->right,v);
      
  }
  void leaves(Node *root, vector<int>&leaf){
      if(!root)return;
      if(!root->left && !root->right){
          leaf.push_back(root->data);
          return;
      }
      leaves(root->left,leaf);
      leaves(root->right,leaf);
  }
    bool isDeadEnd(Node *root) {
        // if(!root)return false;
        // bool b=solver(root,1,INT_MAX);
        // return b;
        vector<int>leaf;
        set<int>v;
        v.insert(0);
        inorder(root,v);
        leaves(root,leaf);
        
        for(int i=0;i<leaf.size();i++){
            if(v.find(leaf[i]-1)!=v.end() && (v.find(leaf[i]+1))!=v.end()){
                return true;
            }
        }
        return false;
    }
};