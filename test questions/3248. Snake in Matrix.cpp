#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
            
            int i=0,j=0;
           
            for(int k=0;k<commands.size();k++){
                if(commands[k]=="UP" && i-1>=0)i=i-1;
                else if(commands[k]=="DOWN" && i+1<n)i=i+1;
                else if(commands[k]=="LEFT" && j-1>=0)j=j-1;
                else if(commands[k]=="RIGHT" && j+1<n)j=j+1;
            }
            return (i*n)+j;
    }
};