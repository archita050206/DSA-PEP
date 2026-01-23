#include <vector>
#include <queue>
#include <string>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        unordered_set<string>st(wordList.begin(), wordList.end());
        st.erase(beginWord);
        while(!q.empty()){
            string word=q.front().first;
            int count=q.front().second;
            if(word==endWord)return count;
            q.pop();
            for(int i=0;i<word.length();i++){
                char original=word[i];
                for(char c='a';c<='z';c++){
                    word[i]=c;
                    if(st.count(word)){
                        st.erase(word);
                        q.push({word,count+1});
                    }
                }
                word[i]=original;
            }
        }
        return 0;
    }
};