#include<vector>
#include<queue>
using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptrptr), right(nullptrptr) {}
     TreeNode(int x) : val(x), left(nullptrptr), right(nullptrptr) {}    
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root)return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int>v;
            for(int i=0;i<size;i++){
               TreeNode* fr=q.front();
                q.pop();
                if(fr->left)q.push(fr->left);
                if(fr->right)q.push(fr->right);
                v.push_back(fr->val);

            }
            ans.push_back(v);
        }
        return ans;

    }
};