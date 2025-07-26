#include<vector>
#include<string>
using namespace std;
class Solution {
  public:
    vector<int> snakePattern(vector<vector<int> > matrix) {
        vector<int>ans;
        for(int i=0;i<matrix.size();i++){
            if((i%2)==0){
            for(int j=0;j<matrix.size();j++){
                ans.push_back(matrix[i][j]);
            }
            
            }
            else{
                for(int j=(matrix.size()-1);j>=0;j--){
                    ans.push_back(matrix[i][j]);
                }
            }
        }
        return ans;
    }
};