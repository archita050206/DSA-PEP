#include<string>
using namespace std;
class Solution {
public:
bool isPrime(int n){
    if(n<=1)return false;
    if(n<=3)return true;
    if(n%2==0 || n%3==0)return false;

    for(int i=5;i*i<=n;i+=6){
        if(n%i==0 || n%(i+2)==0)return false;
    }
    return true;
}
    long long palindrome(int n){
        
        string str=to_string(n);
        for(int i=str.size()-2;i>=0;i--){
            str=str+str[i];
        }
        return stoi(str);
    }
    int primePalindrome(int n) {
        if(n<=2)return 2;
        if(n<=3)return 3;
        if(n<=5)return 5;
        if(n<=7)return 7;
        if(n<=11)return 11;
        for(int i=10;i<100000;i++){
            int s=palindrome(i);
            if(s>=n && isPrime(s))return s;
        }
        return -1;
    }
};