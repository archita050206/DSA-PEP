#include<vector>
#include<string>
using namespace std;
class Solution {

/*
-> check if the jth character is a vowel
-> if yes cnt++
-> when the window size equals k then get the maximum count
-> greater then remove ith character
*/

public:
bool vowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    int maxVowels(string s, int k) {
        int i=0,j=0,cnt=0,maxi=-1;
        int n=s.length();
        while(j<n){
            if(vowel(s[j]))cnt++;
          if(j-i+1>k){
            if(vowel(s[i]))cnt--;
            i++;
          }
          if (j-i+1==k){
            maxi=max(maxi,cnt);
          }
          j++;

        }
        return maxi;
    }
};