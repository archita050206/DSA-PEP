#include <vector>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;

//select the word and push into a map where key is the sorted word (compare the sorted words first)
// TC= O(n*klogk) -> sorting n strings with time klogk

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> mp;
        for (string word : strs)
        {
            string s = word;
            sort(word.begin(), word.end());

            mp[word].push_back(s);
        }
        vector<vector<string>> ans;
        for (auto pair : mp)
        {
            ans.push_back(pair.second);
        }
        return ans;
    }
};