#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0);
#define ll long long

void printLCS(vector<vector<string>>& pos, string s1, int a, int b) {
    if(a == 0 or b == 0) return;

    if(pos[a][b] == "DIG") {
        printLCS(pos, s1, a - 1, b - 1);
        cout << s1[a - 1];
    }
    else if(pos[a][b] == "UP") {
        printLCS(pos, s1, a - 1, b);
    }
    else printLCS(pos, s1, a, b - 1);
}

int main()
{
    fast

    string s1 = "ABCBDAB";
    string s2 = "BDCABA";

    int a = s1.size();
    int b = s2.size();
    

    vector<vector<int>> c(a + 1, vector<int>(b + 1, 0));

    vector<vector<string>> pos(a + 1, vector<string>(b + 1, "0"));

    for (int i = 1; i <= a; ++i) {
        for (int j = 1; j <= b; ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                c[i][j] = c[i - 1][j - 1] + 1;
                pos[i][j] = "DIG";
            }
            else if(c[i - 1][j] >= c[i][j - 1]) {
                c[i][j] = c[i - 1][j];
                pos[i][j] = "UP";
            }
            else {
                c[i][j] = c[i][j - 1];
                pos[i][j] = "PREV";
            }
        }
    }

    for(int i = 0; i <= a; i++) {
        for(int j = 0; j <= b; j++) {
            cout << c[i][j] << '-' << pos[i][j] << "\t";
        }
        cout << '\n';
    }

    printLCS(pos, s1, a, b);

    int x = a, y = b;
    string ans = "";

    while(x > 0 and y > 0) {
        ans += pos[x][y] + " ";
        if(pos[x][y] == "DIG") {
            x--;
            y--;
        }
        else if(pos[x][y] == "UP") {
            x--;
        }
        else y--;
    }
    //reverse(ans.begin(), ans.end());

    cout << '\n' << ans << '\n';
    
    return 0;
}
