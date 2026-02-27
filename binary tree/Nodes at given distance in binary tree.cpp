#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
// A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};


class Solution {

  public:
    Node * findNode(Node *root,int val){
        if(!root)return nullptr;
        if(root->data==val)return root;
        Node *left=findNode(root->left,val);
        if(left!=nullptr)return left;
        Node *right=findNode(root->right,val);
        return right;
    }
    void findParent(Node *root, unordered_map<Node *,Node *>&parent){
        queue<Node *>q;
        q.push(root);
        while(!q.empty()){
            Node *node=q.front();
            q.pop();
            if(node->left){
                q.push(node->left);
                parent[node->left]=node;
            }
            if(node->right){
                q.push(node->right);
                parent[node->right]=node;
            }
            
        }
    }
    vector<int> KDistanceNodes(Node* root, int target, int k) {
        // return the sorted vector of all nodes at k dist
        vector<int>ans;
        if(!root)return ans;
        unordered_map<Node *, Node *>parent;
        Node *t=findNode(root,target);
        findParent(root,parent);
        queue<Node *>q;
        q.push(t);
        unordered_map<Node *, bool>visited;
        visited[t]=true;
        int cnt=0;
        while(!q.empty()){
            int size=q.size();
            if(cnt==k)break;
            for(int i=0;i<size;i++){
                Node *node=q.front();
                q.pop();
                if(node->left && !visited[node->left]){
                    q.push(node->left);
                    visited[node->left]=true;
                }
                if(node->right && !visited[node->right]){
                    q.push(node->right);
                    visited[node->right]=true;
                }
                if(parent[node] && !visited[parent[node]]){
                    q.push(parent[node]);
                    visited[parent[node]]=true;
                }
            }
            cnt++;
        }
        while(!q.empty()){
            Node *t=q.front();
            q.pop();
            ans.push_back(t->data);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};