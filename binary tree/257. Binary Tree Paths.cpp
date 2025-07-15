#include<vector>
#include<string>
using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:

    void solver(TreeNode *root, vector<string>&ans,string temp){
        if(!root)return;
        if(!root->left && !root->right){
            if(!temp.empty())
            temp+="->"+to_string(root->val);
            else{
                temp+=to_string(root->val);
            }
            ans.push_back(temp);
            return;
        }
        if(temp.empty()){
            temp+=to_string(root->val);
        }
        else{
            temp+="->"+to_string(root->val);
        }
        solver(root->left,ans,temp);
        solver(root->right,ans,temp);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        if(!root)return ans;
        string temp="";
        solver(root,ans,temp);
        return ans;
    }
};