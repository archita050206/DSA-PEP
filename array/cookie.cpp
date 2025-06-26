#include<vector>
#include<algorithm>
using namespace std;

// TC= O(glogg + slogs)
// SC= O(1)

int assignCookie(vector<int> &greed, vector<int> &size) {
	int i=0,j=0;
	int g=greed.size();
	int s=size.size();
	int c=0;
	sort(greed.begin(), greed.end());
	sort(size.begin(),size.end());
	while(i<g && j<s){
		 if(greed[i]<=size[j]){
			c++;
			i++;
			j++;
		}
		else j++;

	}
	return c;
	
	
}
