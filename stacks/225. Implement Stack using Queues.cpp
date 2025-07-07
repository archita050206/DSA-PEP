#include<queue>
using namespace std;
class MyStack {
public:
 queue<int>q1;
 // queue<int>q2;
    MyStack() {
       
    }
    
    void push(int x) {
        // q1.push(x);
        q1.push(x);
        int s=q1.size();
        for(int i=1;i<s;i++){
            int y=q1.front();
            q1.pop();
            q1.push(y);
        }
    }
    
    int pop() {
        // int s=q1.size();
        // for(int i=1;i<s;i++){
        //     q2.push(q1.front());
        //     q1.pop();
        // }
        // int val=q1.front();
        // q1.pop();
        // while(!q2.empty()){
        //     q1,push(q2.front());
        //     q2.pop();
        // }
        // return val;
        int y=q1.front();
        q1.pop();
        return y;
    }
    
    int top() {
        // int val=q1.back();
        // return val;
        return q1.front();
        
    }
    
    bool empty() {
        if(q1.empty())return true;
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */