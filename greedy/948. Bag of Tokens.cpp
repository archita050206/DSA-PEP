#include<vector>
#include<algorithm>

using namespace std;
class Solution

// keep scoring from the left (i), when not possible or ypu have a score>0, start from the right by gaining points (j)

{
public:
    int bagOfTokensScore(vector<int> &tokens, int power)
    {
        if (tokens.empty())
            return 0;
        sort(tokens.begin(), tokens.end());
        if (tokens[0] > power)
            return 0;
        int i = 0, sc = 0;
        int maxi = 0;
        int j = tokens.size() - 1;
        while (i <= j)
        {

            if (power >= tokens[i])
            {
                power -= tokens[i];
                sc = sc + 1;
                maxi = max(maxi, sc);
                i++;
            }

            else if (sc >= 1)
            {
                power += tokens[j];
                sc--;
                j--;
            }

            else
                return maxi;
        }
        return maxi;
    }
};