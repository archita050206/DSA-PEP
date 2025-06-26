#include<vector>
#include<set>
using namespace std;
class Solution
{
public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b)
    {

        // Unique solution

         set<int>s;
        for(int i: a){
            s.insert(i);
        }
        for(int j: b){
            s.insert(j);
        }
        vector<int>v(s.begin(), s.end());
        return v;
        

        // vector<int> v;
        // int i = 0, j = 0;
        // int n1 = a.size();
        // int n2 = b.size();
        // int n = n1 + n2;
        // while (i < n1 && j < n2)
        // {
        //     if (a[i] == b[j])
        //     {
        //         if (v.empty() || v.back() != a[i])
        //             v.push_back(a[i]);
        //         i++;
        //         j++;
        //     }
        //     else if (a[i] < b[j])
        //     {
        //         if (v.empty() || v.back() != a[i])
        //             v.push_back(a[i]);
        //         i++;
        //     }
        //     else if (b[j] < a[i])
        //     {
        //         if (v.empty() || v.back() != b[j])
        //             v.push_back(b[j]);
        //         j++;
        //     }
        // }
        // while (i < n1)
        // {
        //     if (v.empty() || v.back() != a[i])
        //         v.push_back(a[i]);
        //     i++;
        // }
        // while (j < n2)
        // {
        //     if (v.empty() || v.back() != b[j])
        //         v.push_back(b[j]);
        //     j++;
        // }
        // return v;
    }
};