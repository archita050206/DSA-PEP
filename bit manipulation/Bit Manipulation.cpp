#include<iostream>
using namespace std;
class Solution {
  public:
    void bitManipulation(int num, int i) {
        // your code here
        int n1=(num>>(i-1));
        int f1=(n1&1);
        
       int f2=(num | (1<<(i-1)));
       int f3= num &  ~(1<<(i-1));
       cout<<f1<<" "<<f2<<" "<<f3;
    }
};