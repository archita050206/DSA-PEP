#include<iostream>
#include<unordered_map>
using namespace std;
class Node{
    public:
    int key,val;
    Node *next,*prev;
    Node(int k,int v){
        key=k;
        val=v;
        next=prev=nullptr;
    }
};
class LRUCache {
public:
    int size;
    unordered_map<int,Node *>mp;
    Node *head,*tail;
    LRUCache(int capacity) {
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
        size=capacity;
    }
    void deleteNode(Node *node){//--> detatching node not deleting it
       
        node->prev->next=node->next;
        node->next->prev=node->prev;
        node->prev=node->next=nullptr;
        
    }
    void beginning(Node *node){//--> adds node to beginning
        node->next=head->next;
        head->next->prev=node;
        head->next=node;
        node->prev=head;
    }
    int get(int key) {//get the value for a particular node
        if(mp.count(key)){
            Node *node=mp[key];
            deleteNode(node);
            beginning(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            Node *node=mp[key];
            node->val=value;
            deleteNode(node);
            beginning(node);
        }
        else{
        if(mp.size()<size){
            
           
            Node *n=new Node(key,value);
            mp[key]=n;
            beginning(n);
        }
        else{
            Node *n=tail->prev;
            mp.erase(n->key);
            deleteNode(n);
            Node *p=new Node(key,value);
            mp[key]=p;
            beginning(p);
        }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */