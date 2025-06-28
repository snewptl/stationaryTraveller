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
const int maxn = 2e5 + 5;
const ll mod = 998244353;
int n, m;
std::vector<std::vector<int>> e;
int a[maxn], b[maxn];
ll sum_a, sum_b;
int dep[maxn];
ll res_a[2], res_b[2];
void bfs() {
    std::queue<int> q;
    q.push(1);
    dep[1] = 1;
    while (!q.empty()) {
        int p = q.front(); q.pop();
        res_a[dep[p] % 2] += a[p];
        res_b[dep[p] % 2] += b[p];
        for (auto v : e[p]) {
            if (dep[v]) continue;
            dep[v] = dep[p] + 1;
            q.push(v);
            
        }
    }
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; std::cin >> T;
    while (T--) {
        std::cin >> n >> m;
        sum_a = sum_b = 0;
        res_a[0] = res_a[1] = 0;
        res_b[0] = res_b[1] = 0;
        for (int i = 1; i <= n; ++i) dep[i] = 0;
        e.clear();
        e.resize(n + 1);
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
            sum_a += a[i];
        }
        for (int i = 1; i <= n; ++i) {
            std::cin >> b[i];
            sum_b += b[i];
        }

        for (int i = 1; i <= m; ++i) {
            int u, v;
            std::cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        bfs();
        int flag = 0;
        for (int i = 1; i <= n; ++i) {
            for (auto j : e[i]) {
                if (dep[i] % 2 == dep[j] % 2) flag = 1;
            }
        }

        if ((sum_a % 2 + 2) % 2 != (sum_b % 2 + 2) % 2) std::cout << "NO\n";
        else if (flag || res_b[0] - res_a[0] == res_b[1] - res_a[1]) std::cout << "YES\n";
        else std::cout << "NO\n";
    }

    

    return 0;
}

// 00 : 13 - 00 : 57