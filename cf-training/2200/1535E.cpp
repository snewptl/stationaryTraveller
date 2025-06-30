#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <assert.h>
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
int q;
ll a[maxn], c[maxn];
int fa[maxn][20];
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> q >> a[0] >> c[0];
    for (int i = 1; i <= q; ++i) {
        int opt;
        std::cin >> opt;
        if (opt == 1) {
            std::cin >> fa[i][0] >> a[i] >> c[i];
            for (int j = 1; j < 20; ++j) {
                fa[i][j] = fa[fa[i][j - 1]][j - 1];
            }
        } else {
            ll v, w;
            std::cin >> v >> w;
            ll ans = 0, num = 0;
            while (w && a[v]) {
                int cur = v;
                for (int j = 19; j >= 0; --j) {
                    if (a[fa[cur][j]]) cur = fa[cur][j];
                }
                ll temp = std::min(a[cur], w);
                w -= temp;
                a[cur] -= temp;
                num += temp;
                ans += c[cur] * temp;
            } 
            std::cout << num << ' ' << ans << std::endl;
        }
    }

    return 0;
}

// 21 : 19 - 21 : 59