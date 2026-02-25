#include<vector>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;
 // Definition for a binary tree node.
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root)return ans;
        map<int, vector<pair<int,int>>>mp;
        queue<pair<TreeNode *,pair<int,int>>>q;
        //row,col
        q.push({root,{0,0}});
        while(!q.empty()){
            TreeNode *node=q.front().first;
            int line=q.front().second.second;
            int row=q.front().second.first;
            q.pop();
            mp[line].push_back({row,node->val});
            if(node->left){
                q.push({node->left,{row+1,line-1}});
            }
            if(node->right){
                q.push({node->right, {row+1,line+1}});
            }
        }
        for(auto v:mp){
            sort(v.second.begin(),v.second.end());
            vector<int>temp;
            for(auto &p: v.second){
                temp.push_back(p.second);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};