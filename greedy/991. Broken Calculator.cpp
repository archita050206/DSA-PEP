class Solution
{
public:
    int brokenCalc(int start, int target)
    {
        // long long cnt=0;
        // while(target>start){
        //     if((target%2)==0){
        //         target/=2;
        //     }
        //     else
        //     {
        //         target=target+1;
        //     }
        //     cnt++;
        // }
        // return cnt + (start-target);

        if (target <= start)
        {
            return start - target;
        }
        if ((target % 2) == 0)
            return 1 + brokenCalc(start, target / 2);
        else
            return 1 + brokenCalc(start, target + 1);
    }
};