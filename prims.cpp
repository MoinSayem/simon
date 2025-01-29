#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0);
#define INF INT_MAX

int main() {
    fast

    int n = 5, m = 5;
    vector<vector<int>> a(n + 1, vector<int>(m + 1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    vector<int> nearest(n + 1, -1), distance(n + 1, INF);
    vector<bool> v(n + 1, false);
    distance[1] = 0;

    int count = 0;
    int totalCost = 0;

    while (count < n - 1) {
        int minDist = INF;
        int vnear = -1;

        for (int i = 1; i <= n; i++) {
            if (!v[i] && distance[i] < minDist) {
                minDist = distance[i];
                vnear = i;
            }
        }

        if (vnear != -1) {
            v[vnear] = true;

            for (int i = 1; i <= n; i++) {
                if (!v[i] && a[vnear][i] < distance[i]) {
                    distance[i]= a[vnear][i];
                    nearest[i] = vnear;
                }
            }

            count++;
        }
    }

    // cout << "Total cost of the MST: " << totalCost << endl;

    cout << "Distances from MST: ";
    for (int i = 1; i <= n; i++) {
        cout << distance[i] << ' ';
    }
    cout << '\n';

    // cout << "Nearest nodes: ";
    // for (int i = 1; i <= n; i++) {
    //     cout << nearest[i] << ' ';
    // }
    // cout << '\n';

    return 0;
}
