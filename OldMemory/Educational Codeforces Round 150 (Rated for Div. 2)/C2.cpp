#include <bits/stdc++.h>
#define all(vec) vec.begin(), vec.end()
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef double db;
typedef long double ldb;
const ll mod = 998244353;
const int maxn = 2e5 + 5;
const double eps = 1e-10;
int n, sum[5][5][maxn], mi[5], nxt[maxn];
string s;
void clear() {
    for (int i = 0; i < 5; i++) {
        for (int k = 0; k < 5; k++)
            for (int j = 0; j < n; j++) {
                sum[i][k][j] = 0;
            }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    cin >> T;
    mi[0] = 1;
    for (int i = 1; i < 5; i++)
        mi[i] = mi[i - 1] * 10;
    while (T--) {
        cin >> s;
        n = s.size();
        clear();
        int mx = 0, ans = 0, fin = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] - 'A' < mx) {
                ans -= mi[s[i] - 'A'];
            } else
                mx = s[i] - 'A', ans += mi[s[i] - 'A'];
            nxt[i] = mx;
        }
        fin = ans;
        for (int i = 0; i < n; i++) {
            if (i)
                for (int j = 0; j < 5; j++) {
                    for (int k = 0; k < 5; k++)
                        sum[j][k][i] = sum[j][k][i - 1];
                }
            else
                for (int j = 0; j < 5; j++) {
                    sum[j][k][i] = 0;
                }
            for (int j = 0; j < 5; j++)
                sum[s[i] - 'A'][nxt[]][i] += mi[s[i] - 'A'];
        }
        mx = 0;
        for (int i = n - 1; i >= 0; i--) {
            int pre = (s[i] - 'A' >= mx ? mi[s[i] - 'A'] : -mi[s[i] - 'A']);
            int del = 0;
            for (int j = s[i] - 'A' + 1; j < 5; j++) {
                if (i)
                    del += sum[j - 1][i - 1];
                int cur = (j >= mx ? mi[j] : -mi[j]);
                fin = max(fin, ans - del * 2 + cur - pre);
            }
            int ad = 0;
            for (int j = s[i] - 'A' - 1; j >= 0; j--) {
                if (i)
                    ad += sum[j][i - 1];
                int cur = (j >= mx ? mi[j] : -mi[j]);
                fin = max(fin, ans + ad * 2 + cur - pre);
            }
            mx = max(mx, s[i] - 'A');
        }
        cout << fin << '\n';
    }

    return 0;
}