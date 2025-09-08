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
const int maxn = 1e3 + 5;
const ll mod = 998244353;
int n;
int a[maxn][maxn];
std::vector<pii> edges;
int val[maxn];
int ind;
int dsu[maxn];
int find(int x) {
    return dsu[x] == x ? x : dsu[x] = find(dsu[x]);
}
void solve(std::vector<int>& vec, int p) {
    if (vec.size() == 1) {
        val[vec[0]] = a[vec[0]][vec[0]];
        edges.push_back({vec[0], p});
        return;
    }
    int rt = ind++, mx = 0;
    for (auto it : vec) {
        dsu[it] = it;
    }
    for (auto it : vec) {
        for (auto that : vec) {
            mx = std::max(mx, a[it][that]);
        }
    }
    val[rt] = mx;
    for (auto it : vec) {
        for (auto that : vec) {
            if (a[it][that] != mx) {
                dsu[find(it)] = find(that);
            }
        }
    }
    for (auto it : vec) {
        if (find(it) != it) continue;
        std::vector<int> cur;
        for (auto that : vec) {
            if (find(that) == it) cur.push_back(that);
        }
        solve(cur, rt);
    }
    if (p) edges.push_back({rt, p});
    
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n;
    ind = n + 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            std::cin >> a[i][j];
        }
    }
    std::vector<int> vec;
    for (int i = 1; i <= n; ++i) vec.push_back(i);
    solve(vec, 0);
    std::cout << ind - 1 << '\n';
    for (int i = 1; i < ind; ++i) std::cout << val[i] << ' ';
    std::cout << '\n' << n + 1 << '\n';
    for (auto [u, v] : edges) {
        std::cout << u << ' ' << v << '\n';
    }

    return 0;
}
// 16 : 41 - 17 : 06