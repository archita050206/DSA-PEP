#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};


class Solution {
  public:
    Node *findNode(Node *root, int target){
        if(!root)return nullptr;
        if(root->data==target){
            return root;
        }
        Node *left=findNode(root->left,target);
        if(left)return left;
        return findNode(root->right,target);
    }
    void findParent(Node *root, unordered_map<Node *,Node *>&parent){
        queue<Node *>q;
        q.push(root);
        while(!q.empty()){
            Node *node=q.front();
            q.pop();
            if(node->left){
                parent[node->left]=node;
                q.push(node->left);
            }
            if(node->right){
                parent[node->right]=node;
                q.push(node->right);
            }
        }
    }
    int minTime(Node* root, int target) {
        // code here
        vector<int>ans;
        if(!root)return 0;
        Node *t=findNode(root, target);
        unordered_map<Node *, Node *>parent;
        findParent(root,parent);
        queue<Node *>q;
        q.push(t);
        unordered_map<Node *, bool>visited;
        visited[t]=true;
        int cnt=0;
        while(!q.empty()){
            int size=q.size();
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
        return cnt-1;
    }
    
};