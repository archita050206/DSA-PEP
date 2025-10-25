#include <iostream>
#include <vector>
#include <cmath>
#include<algorithm>
using namespace std;
void merge(vector<pair<char, double>>& pages, int l, int m, int r) {
    int n1 = m-l+1;
    int n2 =r-m;

    vector<pair<char, double>> L(n1), R(n2);

    for (int i=0;i<n1;i++) L[i]= pages[l + i];
    for (int i =0;i<n2;i++) R[i] =pages[m + 1 + i];
    int i = 0, j = 0, k = l;
    while (i <n1 && j<n2) {
        if (L[i].second>= R[j].second) { 
            pages[k++]= L[i++];
        } else {
            pages[k++] =R[j++];
        }
    }
    while (i< n1)pages[k++] = L[i++];
    while (j <n2) pages[k++] = R[j++];
}


void mergeSort(vector<pair<char, double>>& pages, int l, int r) {
    if(l>=r) return;
    int m = l+ (r-l) / 2;
    mergeSort(pages,l,m);
    mergeSort(pages,m +1,r);
    merge(pages,l,m, r);
}
void ranking(vector<double>& pr, vector<double> &new_pr, vector<vector<int>> &link, int n){
    double d = 0.85;       
    double eps = 0.0001;
    while (true) {
        for (int i=0;i<n;i++) {
            new_pr[i]=(1 - d) / n; 
            for (int j= 0;j<n;j++) {
                int outlinks=0;
                for (int k =0; k< n;k++)
                    outlinks +=link[j][k];

                if (link[j][i]&&outlinks > 0)
                    new_pr[i]+=d*pr[j]/outlinks;
            }
        }

        double diff = 0;
        for (int i =0; i< n;i++)
            diff+=abs(new_pr[i] - pr[i]);
        if (diff < eps)
            break;

        pr =new_pr; 
    }
}
void sortPages(vector<double>& pr, int n) {
    vector<pair<char, double>> pages;
    for (int i=0;i< n;i++)
        pages.push_back({char('A' + i), pr[i]});

    
    mergeSort(pages, 0, n - 1);

    cout << "\nPages are presented in the order:\n";
    for (auto& p :pages)
        cout<<p.first<<endl;
}

int main() {
    int n;
    cout<<"Pease enter the number of pages: ";
    cin>>n;

    vector<vector<int>>link(n, vector<int>(n));
    cout << "Enter adjacency matrix (0 or 1):\n";
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            cin >>link[i][j];
    vector<double> pr(n, 1.0 / n),new_pr(n);

    ranking(pr, new_pr,link,n);
    cout << "\nFinal PageRank values:\n";
    for (int i=0;i< n; i++)
        cout<<"Page "<<char('A' + i)<<": "<<pr[i]<<endl;

    sortPages(pr,n);
    return 0;
}
