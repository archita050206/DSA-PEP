#include <vector>
using namespace std;
class Solution {
public:
    int minimumRefill(vector<int>& plants, int capA, int capB) {
        int n=plants.size(),i=0,j=n-1;
        int turn=0,cnt=0,iniA=capA,iniB=capB;
        while(i<j){
           
           //alice's turn
                if(capA>=plants[i]){
                    capA-=plants[i];
                }
                else {
                    cnt++;
                    capA=iniA;
                    capA-=plants[i];
                }
                i++;
            
            //bob's turn
                if(capB>=plants[j]){
                    capB-=plants[j];
                }
                else{
                    cnt++;
                    capB=iniB;
                    capB-=plants[j];
                }
                j--;
            
            turn++;
        }
         if(i==j){
                if(capA==capB){
                    if(capA<plants[i])cnt++;
                }
                else if(capA>capB){
                    if(capA<plants[i])cnt++;
                }
                else {if(capB<plants[j])cnt++;};
            }
        return cnt;
    }
};