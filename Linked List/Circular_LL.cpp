#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(int val){
        data=val;
        next=nullptr;
    }
};
class Circular{
    public:
    Node *head;
    Circular(){
        head=nullptr;
    }
    void insert(int val){
        Node *n=new Node(val);

    }
};
int main(){
    
}