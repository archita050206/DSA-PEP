#include<iostream>
#include<vector>
#include<climits>
using namespace std;
class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        // code here
        int n1=a.size(),n2=b.size();
        if(n2<n1)return kthElement(b,a,k);
        int l=max(0,k-n2);
        int h=min(k,n1);
        while(l<=h){
            int cut1=l+(h-l)/2;
            int cut2=k-cut1;
            
            int l1=cut1==0?INT_MIN:a[cut1-1];
            int l2=cut2==0?INT_MIN:b[cut2-1];
            int r1=cut1==n1?INT_MAX:a[cut1];
            int r2=cut2==n2?INT_MAX:b[cut2];
            
            if(l1<=r2 && l2<=r1){
                return max(l1,l2);
            }    
            else if(l1>r2){
                h=cut1-1;
            }
            else l=cut1+1;
        }
        return -1;
    }
};