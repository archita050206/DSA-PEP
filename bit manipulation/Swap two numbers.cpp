#include<vector>
using namespace std;
class Solution {
  public:
    pair<int, int> get(int a, int b) {
        // complete the function here
        a=a^b;
        b=a^b;
        a=a^b;
        return {a,b};
    }
};