#include<queue>
#include<map>

using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = nullptr;
    }
}; 


class Solution {
  public:
    vector<int> topView(Node *root) {
        // code here
        vector<int>v;
        if(!root)return v;
        queue<pair<Node *,int>>q;
        q.push({root,0});
        map<int,int>mp;
        while(!q.empty()){
            
            int size=q.size();
            for(int i=0;i<size;i++){
                Node *node=q.front().first;
                int line=q.front().second;
                q.pop();
                if(!mp.count(line)){
                    mp[line]=node->data;
                }
                if(node->left){
                    q.push({node->left,line-1});
                }
                if(node->right){
                    q.push({node->right,line+1});
                }
            }
        }
        for(auto p: mp){
            v.push_back(p.second);
        }
        return v;
    }
};