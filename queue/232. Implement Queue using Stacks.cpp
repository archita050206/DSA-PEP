
#include<stack>
using namespace std;
class MyQueue {
public:
stack<int>st1,st2;
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!st1.empty()){
            int v=st1.top();
            st1.pop();
            st2.push(v);
        }
        st1.push(x);
        while(!st2.empty()){
            int v=st2.top();
            st2.pop();
            st1.push(v);
        }
    }

    
    int pop() {
        int a=st1.top();
        st1.pop();
        return a;
    }
    
    int peek() {
        return st1.top();
        
    }
    
    bool empty() {
        return st1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */