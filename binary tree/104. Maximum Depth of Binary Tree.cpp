#include<vector>
#include<queue>

using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr ) {}    
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root)return 0;
        int left=maxDepth(root->left);
        int right=maxDepth(root->right);
        return 1+max(left,right);
    }

    // int maxDepth(TreeNode* root) {
    //     if(!root)return 0;
    //    int cnt=0;
    //    queue<TreeNode *>q;       
    //    q.push(root);
    //    while(!q.empty()){
    //    cnt++;
    //     int size=q.size();
    //     for(int i=0;i<size;i++){
    //          TreeNode *node=q.front();
    //             q.pop();
    //             if(node->left)q.push(node->left);
    //             if(node->right)q.push(node->right);

    //     }
    //    } 
    //    return cnt;                         
    // }
};