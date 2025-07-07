#include<queue>
#include<string>
#include<vector>

using namespace std;
// Function to generate binary numbers from 1 to N using a queue.
vector<string> generate(int n) {
    // Your code here
    vector<string>ans;
    queue<string>q;
    q.push("1");
    for(int i=0;i<n;i++){
        ans.push_back(q.front());
        q.push(q.front()+"0");
        q.push(q.front()+"1");
        q.pop();
    }
    return ans;
}
