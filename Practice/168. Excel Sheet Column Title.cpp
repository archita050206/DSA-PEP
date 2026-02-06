class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans;
       
        while(columnNumber>=1){
            int d=columnNumber%26;
            if(d==0)
            {ans.push_back('Z');
            columnNumber=columnNumber/26-1;
            
            }
            else {
                char c= d+'A'-1;
                ans.push_back(c);
                columnNumber=columnNumber/26;
            }
            

        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};