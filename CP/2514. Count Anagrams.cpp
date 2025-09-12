#include<vector>
#include<string>
using namespace std;
long long M=1e9+7;
class Solution {
public:
    vector<long long>fact;
    void factorial(int n){
        fact.assign(n+1,1);
        for(int i=2;i<=n;i++){
            fact[i]=(fact[i-1]*i)%M;
        }
    }
    long long permutation(int len, vector<int>&freq){
        long long ans=fact[len];
        for(int i:freq){
            if(i>1){
                ans=(ans*inverseMod(fact[i]))%M;
            }
            
        }
        return ans;
    }
    long long modPow(long long base,long long exp){
        long long res=1;
        while(exp>0){
            if(exp&1) res=(res*base)%M;
            base=(base*base)%M;
            exp>>=1;
        }
        return res;
    }

    long long inverseMod(long long n){
        return modPow(n,M-2); // Fermat’s little theorem
    }
    int countAnagrams(string s) {
        factorial(s.size());
        int i=0,wordLen=0;
        long long res=1;
        while(i<s.size()){
            vector<int>freq(26,0);
            while(i<s.size() && s[i]!=' '){
                wordLen++;
                freq[s[i]-'a']++;
                i++;

            }
            res=(res*permutation(wordLen,freq))%M;
            i++;
            wordLen=0;

        }
        return res;
    }
};