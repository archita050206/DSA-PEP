#include<vector>
#include<climits>
using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr ), right(nullptr ) {}
     TreeNode(int x) : val(x), left(nullptr ), right(nullptr ) {}    
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:
    TreeNode *solver(vector<int>& nums, int l, int h){
        if(l>h)return nullptr;
        int mid=(l+h)/2;
        TreeNode *node=new TreeNode(nums[mid]);
        node->left=solver(nums,l,mid-1);
        node->right=solver(nums,mid+1,h);
        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0)return nullptr;
        int l=0,h=nums.size()-1;
        TreeNode *root=solver(nums,l,h);
        return root;
    }
};