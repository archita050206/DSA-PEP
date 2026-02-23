#include<vector>
#include<algorithm>
using namespace std;
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};


class Solution {
  public:
    void leftBoundary(Node *root, vector<int>&ans){
        Node *temp=root;
        while(temp){
            if(!temp->left&&!temp->right)break;
            if(temp->left){
                ans.push_back(temp->data);
                temp=temp->left;
            }
            else {
                ans.push_back(temp->data);
                temp=temp->right;
            }
        }
        
    }
    void rightBoundary(Node *root, vector<int>&ans){
        Node *temp=root;
        vector<int>t;
        while(temp){
            if(!temp->left && !temp->right)break;
            t.push_back(temp->data);
            if(temp->right){
                temp=temp->right;
            }
            else temp=temp->left;
        }
        reverse(t.begin(),t.end());
        for(int i: t){
            ans.push_back(i);
        }
    }
     void addLeaves(Node *root, vector<int>&ans){
         if(!root)return;
         if(!root->left && !root->right){
             ans.push_back(root->data);
             return;
         }
         addLeaves(root->left,ans);
         addLeaves(root->right,ans);
         
     }
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int>ans;
        if(!root)return ans;
        ans.push_back(root->data);
        if(root->left){
            leftBoundary(root->left,ans);
        }
        addLeaves(root->left,ans);
        addLeaves(root->right,ans);
        if(root->right){
            rightBoundary(root->right,ans);
            
        }
        
        return ans;
    }
};