#include<vector>
#include <string>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(),products.end());

        vector<vector<string>>ans;
        int n=searchWord.length();
        // if(n<2)return ans;
        for(int i=1;i<=n;i++){
            string pre=searchWord.substr(0,i);
            vector<string>temp;
            for(string w: products){
                if(w.length()>=i && w.compare(0,i,pre)==0){
                    temp.push_back(w);
                    if(temp.size()==3)break;
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};