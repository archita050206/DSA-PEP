class Solution {

//bruteforce/usual: start by checking the righmost bit of the 2 numbers, it they are different then change the digit, then right shift , keep repeating

public:
    int minBitFlips(int start, int goal) {
        int num=start^goal;
        int cnt=0;
        while(num>0){
            num=num&(num-1);
            cnt++;
        }
        return cnt;
    }
};