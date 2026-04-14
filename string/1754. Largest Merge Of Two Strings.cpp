#include<string>
#include<climits>
using namespace std;
class Solution {
public:
    string largestMerge(string word1, string word2) {
        string merge="";
        int i=0,j=0,n1=word1.length(), n2=word2.length();
        // if(n2>n1){
        //     string temp=word1;
        //     word1=word2;
        //     word2=temp;
        // }
        // n1=word1.length(), n2=word2.length();
        while(i<n1 && j<n2){
            if(word1.substr(i)>=word2.substr(j)){
                merge+=word1[i];
                i++;
                
            }
            else {
                merge+=word2[j];
                j++;
                
            }
        }
        while(i<n1){
            merge+=word1[i];
            i++;
        }
        while(j<n2){

            merge+=word2[j];
            j++;
        }
        return merge;
    }
};