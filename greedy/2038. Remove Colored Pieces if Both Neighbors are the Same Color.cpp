#include <string>

using namespace std;
class Solution {
public:
    bool winnerOfGame(string colors) {
        
        int a=0,b=0;
        for(int i=1;i<colors.length();i++){
            if((colors[i]==colors[i-1]) && (colors[i]==colors[i+1])){
                if(colors[i]=='A')a++;
                else b++;
            }
        }
        return (a>b)?true:false;
    }
};