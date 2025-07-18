#include <vector>
#include <algorithm>

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
    vector<int> mergeArr(vector<int>&v1,vector<int>&v2){
        int i=0,j=0;
        int n1=v1.size(),n2=v2.size();
        vector<int>ans;
        while(i<n1 && j<n2){
            if(v1[i]<=v2[j]){
                ans.push_back(v1[i]);
                i++;
            }
            else if(v1[i]>v2[j]){
                ans.push_back(v2[j]);
                j++;
            }
            
        }
        while(i<n1){
            ans.push_back(v1[i]);
            i++;
        }
        while(j<n2){
            ans.push_back(v2[j]);
            j++;
        }
        return ans;
    }
    void inorder(Node *root, vector<int>&v){
        if(!root)return;
        inorder(root->left,v);
        v.push_back(root->data);
        inorder(root->right,v);
    }
    vector<int> merge(Node *root1, Node *root2) {
        // Your code here
        vector<int>ans;
        if(!root1 && !root2)return ans;
        
        vector<int>v1,v2;
        
        inorder(root1,v1);
        inorder(root2,v2);
        ans=mergeArr(v1,v2);
        return ans;
    }
};