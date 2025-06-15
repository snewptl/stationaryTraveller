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
const int maxn = 1e6 + 5;
const ll mod = 998244353;
ll n, m;
int vis[maxn * 20];
ll count[25];
std::vector<int> vec[maxn];
int in[maxn];
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    // std::cin >> T;
    while (T--) {
        std::cin >> n >> m;
        ll res = 0;
        for (int i = 1; i <= 20; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (!vis[j * i]) {
                    vis[j * i] = 1;
                    ++res;
                }     
            }
            count[i] = res;
        }
        ll ans = 0;
        for (ll i = 1; i <= n; ++i) {
            if (in[i]) continue;
            if (i == 1) {
                ans += 1;
                continue;
            } else {
                for (ll j = i; j <= n; j = j * i) {
                    vec[i].push_back(j);
                    in[j] = 1;
                } 
            }
        }
        for (int i = 1; i <= n; ++i) {
            if (vec[i].empty()) continue;
            ans += count[vec[i].size()];
        }
        std::cout << ans << '\n';
    }

    return 0;
}

// 16 : 20