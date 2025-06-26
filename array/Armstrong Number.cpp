#include <bits/stdc++.h> 
bool isArmstrong(int num) {
    // Write your code here
    int l=0,k=num,s=num,sum=0;
    // while(k!=0){
    //     k=k/10;
    //     l++; //3
    // }

    l=floor(log10(num)+1);// IMPORTANT

    while(s!=0){
        int d=s%10;
        sum+=pow(d,l);
        s=s/10;
    }
    if(sum==num)return true;
    return false;

}