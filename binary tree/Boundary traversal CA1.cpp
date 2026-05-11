#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
    left = NULL;
    right = NULL;
    }
};

Node* buildTree(vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return NULL;
    Node* root = new Node(arr[0]);
    queue<Node*> q;
    q.push(root);

    int i = 1;

    while (!q.empty() && i < n) {
        Node* curr = q.front();
        q.pop();
        if (i < n && arr[i] != -1) {
            curr->left = new Node(arr[i]);
            q.push(curr->left);
        }
        i++;
        if (i < n && arr[i] != -1) {
            curr->right = new Node(arr[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}
void leftLeaf(Node *root, vector<int>&ans){
    if(!root)return;
    Node *temp=root;
    while(temp){
        if(!temp->left && !temp->right)break;
        ans.push_back(temp->data);
        temp=temp->left;
    }
}
void rightLeaf(Node *root,vector<int>&ans){
    if(!root)return;
    Node *temp=root;
    while(temp){
        if(!temp->left && !temp->right)break;
        ans.push_back(temp->data);
        temp=temp->right;
    }
}
void leaves(Node *root, vector<int>&ans){
    if(!root)return;
    if(!root->left && !root->right){
        ans.push_back(root->data);return;
    }
    leaves(root->left,ans);
    leaves(root->right,ans);
}
int main() {
    vector<int>arr;
    //int arr[] = {1,2,3,4,5,6,7};
    //int n = 7;
    int x;
    while(cin>>x){
        arr.push_back(x);
    }
    
    Node* root = buildTree(arr);
    vector<int>ans;
    ans.push_back(root->data);
    leftLeaf(root->left,ans);
    leaves(root->left,ans);
    leaves(root->right,ans);
    rightLeaf(root->right,ans);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}