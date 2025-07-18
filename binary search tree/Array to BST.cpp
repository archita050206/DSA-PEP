#include<vector>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val)
        : data(val)
        , left(nullptr)
        , right(nullptr) {}
};


class Solution {
  public:
  
  Node *solver(vector<int>& nums, int l, int h){
      if(l>h)return nullptr;
      int mid=(l+h)/2;
      Node *node=new Node(nums[mid]);
      node->left=solver(nums,l,mid-1);
      node->right=solver(nums,mid+1,h);
      return node;
  }
    Node* sortedArrayToBST(vector<int>& nums) {
        
        if(nums.size()==0)return nullptr;
        int l=0,h=nums.size()-1;
        Node *root=solver(nums,l,h);
        return root;
    }
};