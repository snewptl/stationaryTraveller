#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;
typedef double db;
typedef long double ldb;
const int maxn = 2e5 + 5;
const ll mod = 998244353;
int p[maxn], q[maxn];
ll power[maxn];
int n;
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1; std::cin >> T;
    while (T--) {
        std::cin >> n;
        power[0] = 1;
        for (int i = 1; i < n; ++i) power[i] = power[i - 1] * 2, power[i] %= mod;
        for (int i = 1; i <= n; ++i) std::cin >> p[i];
        for (int i = 1; i <= n; ++i) std::cin >> q[i];
        int up = 1, down = 1;
        for (int i = 1; i <= n; ++i) {
            if (p[i] > p[up]) up = i;
            if (q[i] > q[down]) down = i;
            ll res = 0;
            if (p[up] > q[down]) {
                res = (power[p[up]] + power[q[i - up + 1]]) % mod;
            } else if (p[up] == q[down]) {
                if (q[i - up + 1] > p[i - down + 1]) res = (power[p[up]] + power[q[i - up + 1]]) % mod;
                else res = (power[p[i - down + 1]] + power[q[down]]) % mod;
            } else {
                res = (power[p[i - down + 1]] + power[q[down]]) % mod;
            }
            std::cout << res << ' ';
        }
        std::cout << '\n';
    }
    return 0;
}
