#include <climits>
#include <vector>

using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
        : data(val), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    void inorder(Node *root, vector<int>&v){
      if(!root)return;
      inorder(root->left,v);
      v.push_back(root->data);
      inorder(root->right,v);
  }
    int floor(Node* root, int x) {
        // Code here
        if(!root)return -1;
        vector<int>v;
        inorder(root,v);
        int l=0,h=v.size()-1,ans=-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(v[mid]<=x){
                ans=v[mid];
                l=mid+1;
            }
            else h=mid-1;
        }
        return ans;
        
    }
};