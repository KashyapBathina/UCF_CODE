
#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

int AFTER = 1;
int BEFORE = 2;
int ADJ = 3;

int main() {
    int n, m;
    cin >> n >> m;
    vvi adj(n+1, vi(n+1, 1));
    vvi aft(n+1, vi(n+1, 1));
    for (int i = 0; i < m; i++) {
        int ty;
        char a, b;
        cin >> ty >> a >> b;
        a-='A';
        b-='A';
        if (ty == BEFORE) {
            swap(a,b); ty = AFTER;
        }
        if (ty == AFTER) {
            aft[b][a] = 0;
        }
        if (ty == ADJ) {
            adj[a][b] = adj[b][a] = 0;
        }
    }


    vvi memo(n + 1, vi(2<<n));
    memo[n][1<<n] = 1;

    int ans = 0;

    for (int i = 1+(1<<n); i < (2<<n); i++) {
        for (int a = 0; a < n; a++) {
            if (!((i>>a)&1)) continue; // new last act
            for (int b = 0; b <= n; b++) {
                if (a == b) continue;
                if (!((i>>b)&1)) continue; // second to last act
                if (!adj[a][b]) continue;
                int good = 1;
                for (int c = 0; c < n; c++) {
                    if (!((i>>c)&1) && !aft[a][c]) {
                        good = 0;
                        break;
                    }
                }
                if (!good) continue;
                memo[a][i] += memo[b][i-(1<<a)];    
            }
            if (i+1 == (2<<n)) ans += memo[a][i];
        }
    }
    cout << ans << endl;

    return 0;
}
