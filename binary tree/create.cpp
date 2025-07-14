#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int val){
        data=val;
        left=right=nullptr;
    }
};
class OP{
    public:
    Node *root;
    OP(){
        root=nullptr;
    }
    void insert(int val){
        Node *n=new Node(val);
        if(!root){
            root=n;
            return;
        }
        Node *temp=root;
        while(true){
            if(val<temp->data){
                if(!temp->left){
                    temp->left=n;
                    break;
                }
                temp=temp->left;
            }
            else if(val>temp->data){
                if(!temp->right){
                    temp->right=n;
                    break;
                }
                temp=temp->right;
            }
            else{
                delete n;
                break;
            }
        }
    }

};
int main(){

}