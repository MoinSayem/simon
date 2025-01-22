#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0);
#define ll long long

int main()
{
    fast

    int n; cin >> n;
    vector<vector<int>> a(n, vector<int>(n, 0));
    

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << i + 1 << ' ' << j + 1 << ": " << a[i][j] << '\n';
        }
        cout << '\n';
    }
    return 0;
}
