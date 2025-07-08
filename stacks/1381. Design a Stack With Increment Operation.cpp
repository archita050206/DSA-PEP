#include<stack>
#include<vector>
#include<string>

using namespace std;
class CustomStack {
public:
vector<int>v;
int k=0;
    CustomStack(int maxSize) {
        
     k=maxSize;
    }
    
    void push(int x) {
        if(v.size()<k){
            v.push_back(x);
        }
    }
    
    int pop() {
        int s=0;
        if(v.size()==0)return -1;
        if(v.size()>0){
            s=v[v.size()-1];
            v.pop_back();
        }
        return s;
    }
    
    void increment(int k, int val) {
        if(v.size()<k){
            for(int i=0;i<v.size();i++){
                v[i]+=val;
            }
        }
        else{
        for(int i=0;i<k;i++){
            v[i]+=val;
        }
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */