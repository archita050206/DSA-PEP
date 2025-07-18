#include <climits>
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
    void solver(Node *root, int &k,int &ans, int &sum){
    if(!root)return;
    
    solver(root->left,k,ans,sum);
    k--;
    sum+=root->data;
    if(k==0){
        ans=sum;
        return;
    }
    solver(root->right,k,ans,sum);
    
}
int sum(Node* root, int k) {
    int sum=0;
    int ans=0;
    solver(root,k,ans,sum);
    return ans;
}
};