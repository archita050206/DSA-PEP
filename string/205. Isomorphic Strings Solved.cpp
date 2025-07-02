#include<unordered_map>
#include<string>
using namespace std;

// create 2 maps, Ex: egg, add

// map1->
// g->d
// e->a

// map2->
// d->g
// a->e

// TC= O(n)
// SC= O(1) // map can store atmost 256 characters

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length())return false;
        unordered_map<char,char>mp1,mp2;
        for(int i=0;i<s.length();i++){
            char c1=s[i];
            char c2=t[i];
            if(mp1.count(c1)){
                if(mp1[c1]!=c2){
                    return false;
                }
                
            }
            else{
                    mp1[c1]=c2;
            }

            if(mp2.count(c2)){
                if(mp2[c2]!=c1)return false;
            }
            else{
                mp2[c2]=c1;
            }
        }
        return true;


    }
};