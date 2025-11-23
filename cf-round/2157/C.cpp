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
const int maxn = 2e5 + 5;
const ll mod = 998244353;
int n, k, q;
std::vector<std::vector<pii>> vec;
std::vector<int> vis, a;
int main() {
    #ifndef ONLINE_JUDGE
    freopen("0_input.txt", "r", stdin);
    // freopen("0_output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> n >> k >> q;
        vec.clear();
        vec.resize(3);
        vis.clear();
        vis.resize(n + 1, 0);
        a.clear();
        a.resize(n + 1, 0);
        for (int i = 0; i < q; ++i) {
            int c, l, r;
            std::cin >> c >> l >> r;
            vec[c].push_back({l, r});
            if (c == 2) {
                for (int j = l; j <= r; ++j) {
                    vis[j] = 1;
                }
            }
        }
        for (auto [l, r] : vec[1]) {
            for (int i = l; i <= r; ++i) {
                if (vis[i]) a[i] = k + 1;
                else a[i] = k;
            } 
        } 
        int cur = 0;
        for (int i = 1; i <= n; ++i) {
            if (vis[i] && !a[i]) {
                a[i] = cur;
                cur = (cur + 1) % k;
            }
        }
        for (int i = 1; i <= n; ++i) {
            std::cout << a[i] << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}
