#include<stack>
#include<vector>
#include<string>

using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode *temp=head;
        vector<int>v;
        while(temp){
            v.push_back(temp->val);
            temp=temp->next;
        }
        vector<int>ans(v.size(),0);
        stack<int>st;
        for(int i=(ans.size()-1);i>=0;i--){
            while(!st.empty() && v[i]>=st.top())st.pop();
            if(!st.empty() && v[i]<st.top())ans[i]=st.top();
            st.push(v[i]);
        }
        return ans;
    }
};