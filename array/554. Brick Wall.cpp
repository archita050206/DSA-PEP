class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int n=wall.size();
        unordered_map<long long,int>mp;
        long long col=0;
        for(long long i:wall[0])col+=i;
        for(int i=0;i<n;i++){
            long long sum=0;
            for(long long j:wall[i]){
                
                    sum+=j;
                    if(sum<col){
                    mp[sum]++;
                    }
                
            }
        }

        int maxi=0;
        for(auto p: mp){
            maxi=max(maxi,p.second);
        }
        return (n-maxi);
    }
};