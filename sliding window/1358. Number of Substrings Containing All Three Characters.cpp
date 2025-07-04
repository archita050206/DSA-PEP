#include <map>
#include <climits>
using namespace std;
class Solution
{
/*
create  map, store the jth characters of the string, when map.size()==3 then count+=(n-j), remove ith character from map and then inc i

TC= O(n*k) -> k is v small
SC = O(1)-> map of constant size 3

*/

public:
    int numberOfSubstrings(string s)
    {
        int i = 0, j = 0;
        int n = s.length();
        map<char, int> mp;
        int cnt = 0;
        while (j < n)
        {

            mp[s[j]]++;

            while (mp.size() == 3)
            {
                cnt += (n - j);
                mp[s[i]]--;
                if (mp[s[i]] == 0)
                {
                    mp.erase(s[i]);
                }

                i++;
            }
            j++;
        }
        return cnt;
    }
};