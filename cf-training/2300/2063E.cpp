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
std::vector<std::vector<ll>> vec;
std::vector<std::vector<int>> e;
int loc[maxn];
ll sum[maxn], count[maxn];
int n;
ll ans;
void dfs(int u, int p) {
    int son = 0, mx_size = 0;
    for (auto v : e[u]) {
        if (v == p) continue;
        dfs(v, u);
        if (mx_size <= vec[loc[v]].size()) {
            mx_size = vec[loc[v]].size();
            son = v;
        }
    }
    if (son) {
        loc[u] = loc[son];
        sum[u] = sum[son];
        count[u] = count[son];
    } else {
        loc[u] = u;
        sum[u] = 0;
        count[u] = 0;
    }
    std::vector<ll> &to = vec[loc[u]];
    for (auto v : e[u]) {
        if (v == p || v == son) continue;
        std::vector<ll> &from = vec[loc[v]];
        int len_from = from.size(), len_to = to.size();
        ll buffer_count = 0, buffer_sum = 0;
        for (int i = len_from - 1, j = len_to - 1; i >= 0; --i, --j) {
            ans += buffer_sum * from[i];
            ans += from[i] * ((len_from - i) * 2 - 1) * (count[u] - buffer_count);
            buffer_sum += to[j] * ((len_to - j) * 2 - 1);
            buffer_count += to[j];
        }
        for (int i = len_from - 1, j = len_to - 1; i >= 0; --i, --j) {
            to[j] += from[i];
            sum[u] += ((len_from - i) * 2 - 1) * from[i];
            count[u] += from[i];
        }        
    }
    sum[u] += count[u] * 2;
    to.push_back(1);
    sum[u] += 1;
    count[u] += 1;
}
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
        std::cin >> n;
        vec.clear();
        e.clear();
        vec.resize(n + 1);
        e.resize(n + 1);
        ans = 0;
        for (int i = 1; i < n; ++i) {
            int u, v;
            std::cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        dfs(1, 0);
        std::cout << ans << '\n';
    }

    return 0;
}
// 12 : 48 - 13 : 02
// 15 : 20 - 16 : 20