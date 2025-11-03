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
#include <unordered_map>
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;
typedef double db;
typedef long double ldb;
const int maxn = 1e6 + 5;
const ll mod = 998244353;
int n, m, q;
int dsu[maxn];
std::unordered_map<ll, int> mp;
std::vector<pii> e;
int find(int x) {
    return dsu[x] == x ? x : dsu[x] = find(dsu[x]);
}
int sum2[maxn], sum3[maxn];
ll hsh(int u, int v) {
    return 1ll * u * n + v;
}
void rec(int u, int v, int idx) {
    if (u > v) std::swap(u, v);
    if (!mp.count(hsh(u, v))) mp[hsh(u, v)] = idx;
    else if (idx < mp[hsh(u, v)]) mp[hsh(u, v)] = idx;
}
bool check(int x) {
    for (int i = 0; i < n; ++i) dsu[i] = i;
    for (auto [u, v] : e) {
        if (mp.count(hsh(u, v)) && mp[hsh(u, v)] <= x) continue;
        if (find(u) != find(v)) {
            dsu[find(u)] = find(v);
        }
    }
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (dsu[i] == i) count += 1;
    }
    return count > 1;
}
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
        mp.clear();
        std::cin >> n >> m >> q;
        e.clear();
        for (int i = 1; i <= m; ++i) {
            int u, v;
            std::cin >> u >> v;
            if (u > v) std::swap(u, v);
            e.push_back({u, v});
        }
        sum2[1] = 1;
        sum3[1] = 1;
        for (int i = 2; i <= q; ++i) {
            sum2[i] = sum2[i - 1] * 2 + 1, sum2[i] %= n;
            sum3[i] = sum3[i - 1] * 3 + 1, sum3[i] %= n;
        }
        for (int i = 1; i <= q; ++i) {
            int a, b;
            std::cin >> a >> b;
            a = (a + sum2[i - 1]) % n;
            b = (b + sum3[i - 1]) % n;
            rec(a, b, i);
        }
        int l = 0, r = q, res = q + 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (check(mid)) {
                res = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        for (int i = 1; i < res; ++i) std::cout << "1\n";
        for (int i = std::max(res, 1); i <= q; ++i) std::cout << "0\n";
    }

    return 0;
}
