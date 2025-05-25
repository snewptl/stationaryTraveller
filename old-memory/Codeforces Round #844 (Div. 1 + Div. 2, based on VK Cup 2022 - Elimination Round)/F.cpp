#include <bits/stdc++.h>
#define el "\n"
using namespace std;

const int N = 4e5 + 50;

int f[5][1500][1500], M, a;

int get_P(int n) {
    int a = sqrt(n);
    if (a * a < n && a * a + a >= n) {
        return 2 * a + 1;
    }
    if (a * a + a < n && n <= (a + 1) * (a + 1)) {
        return 2 * (a + 1);
    }
    return 2 * a;
}

void precalc() {
    a = sqrt(N) + 5;
    f[0][0][a] = 1;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j <= a; j++) {
            for (int was = a; was >= 0; was--) {
                if (was && j + was <= a) {
                    (f[i][j + was][was] += f[i][j][was]) %= M;
                }
                if (was) {
                    (f[i][j][was - 1] += f[i][j][was]) %= M;
                }
            }
            (f[i + 1][j][a] += f[i][j][0]) %= M; 
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int q, type;
    cin >> q >> type;
    if (type == 2) {
        cin >> M;
        precalc();
    }
    while (q--) {
        int n;
        cin >> n;
        int p = get_P(n);
        if (type == 1) {
            int _n, _m;
            for (int x = 1; x <= p; x++) {
                int y = p - x;
                if (x + y == p && x * y >= n) {
                    _n = x; _m = y;
                    break;
                }
            }
            vector <vector <char> > ans(_n, vector <char> (_m, '#'));
            cout << _n << " " << _m << "\n";
            for (int i = 0; i < _n * _m - n; i++) {
                ans[i][0] = '.';
            }
            for (int i = 0; i < _n; i++, cout << el) {
                for (int j = 0; j < _m; j++) {
                    cout << ans[i][j];
                }
            }

            continue;
        }

        int ans = 0;
        for (int x = 1; x <= p; x++) {
            int y = p - x;
            if (x + y == p && x * y >= n) {
                (ans += f[4][x * y - n][a]) %= M;
            }
        }
        cout << p * 2 << " " << ans << "\n";
    }
}