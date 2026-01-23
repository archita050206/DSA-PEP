// User function Template for C++
#include<vector>
#include<string>
#include<unordered_set>
#include<queue>
using namespace std;
class Solution {
  public:
    vector<vector<string>> findSequences(string beginWord, string endWord,
                                         vector<string>& wordList) {
        // code here
         queue<vector<string>>q;
        vector<string>currentLevel;
        unordered_set<string>st(wordList.begin(), wordList.end());
        q.push({beginWord});
        currentLevel.push_back(beginWord);
        int lvl=0;
        vector<vector<string>>ans;
        while(!q.empty()){
            vector<string>v=q.front();
            q.pop();
            //remove words from prev level
            if(v.size()>lvl){
                lvl++;
                for(string w: currentLevel){
                    st.erase(w);
                }
            }
            string word= v.back();
            if(word==endWord){
                if(ans.size()==0)ans.push_back(v);
                else if(ans[0].size()==v.size())ans.push_back(v);
            }
            for(int i=0;i<word.length();i++){
                char original=word[i];
                for(char c='a';c<='z';c++){
                    word[i]=c;
                    if(st.count(word)){
                        v.push_back(word);
                        currentLevel.push_back(word);
                        q.push(v);
                        v.pop_back();
                    }
                }
                word[i]=original;
            }
        }
        return ans;
    }
};