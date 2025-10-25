#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n;
    cout << "Enter number of pages: ";
    cin >> n;

    vector<vector<int>> link(n, vector<int>(n));
    cout << "Enter adjacency matrix (0 or 1):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> link[i][j];

    double d = 0.85;       // damping factor
    double eps = 0.0001;   // convergence threshold
    vector<double> pr(n, 1.0 / n), new_pr(n);

    while (true) {
        for (int i = 0; i < n; i++) {
            new_pr[i] = (1 - d) / n; // teleportation factor

            for (int j = 0; j < n; j++) {
                int outlinks = 0;
                for (int k = 0; k < n; k++)
                    outlinks += link[j][k];

                if (link[j][i] && outlinks > 0)
                    new_pr[i] += d * pr[j] / outlinks;
            }
        }

        double diff = 0;
        for (int i = 0; i < n; i++)
            diff += fabs(new_pr[i] - pr[i]);
        if (diff < eps)
            break;

        pr = new_pr; // update for next iteration
    }

    cout << "\nFinal PageRank values:\n";
    for (int i = 0; i < n; i++)
        cout << "Page " << char('A' + i) << ": " << pr[i] << endl;

    return 0;
}
