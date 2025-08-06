#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <assert.h>
#include <memory.h>
#include <cmath>
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;
typedef double db;
typedef long double ldb;
const int maxn = 3e5 + 5;
const ll mod = 998244353;
int f[20][20], g[maxn][20];
int n, c, len;
int tot;
std::string s;
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> n >> c >> len >> s;
        tot = n - len + 1;
        std::vector<int> cnt;
        cnt.clear();
        cnt.resize(20);
        for (int i = 0; i < len; ++i) {
            cnt[s[i] - 'A'] += 1;
        }
        for (int i = len - 1; i < n; ++i) {
            for (int j = 0; j < c; ++j) {
                if (!cnt[j]) continue;
                for (int k = 0; k < c; ++k) {
                    if (!cnt[j]) continue;
                    f[j][k] += 1;
                }
            }
            cnt[s[i + 1 - len] - 'A'] -= 1;
            if (i + 1 < n) cnt[s[i + 1] - 'A'] += 1;
        }
        for (int i = 0; i < c; ++i) {
            for (int j = 0; j < (1 << i) - 1; ++j) {
                
            }
        }
    }

    return 0;
}
// 21 : 50 - 22 : 46