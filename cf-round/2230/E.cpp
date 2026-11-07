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
const int maxn = 4e5 + 5;
const ll mod = 998244353;
int n, m;
ll p[maxn], c[maxn];
ll tp[maxn], tc[maxn];
ll d[maxn];
std::set<pli> s[2];
int pt[2];
ll ans[maxn];
ll check(int id, ll x) {
    if (x < tc[id]) return 0;
    if (x < tc[id] + d[id]) return x;
    return tc[id] + d[id];
}
void solve() {
    for (int i = 0; i < 2; ++i) {
        s[i].clear();
        pt[i] = 0;
    }
    std::vector<std::pair<pll, int>> people;
    for (int i = 1; i <= m; ++i) {
        people.push_back({{tp[i], tc[i]}, i});
    }
    std::sort(all(people));
    std::vector<pll> product;
    for (int i = 1; i <= n; ++i) {
        product.push_back({p[i], c[i]});
    }
    std::sort(all(product));
    for (int i = 0; i < product.size(); ++i) {
        s[1].insert({product[i].second, i});
    }
    for (auto [cur, id] : people) {
        auto [tp, tc] = cur;
        while (pt[0] < product.size() && product[pt[0]].first < tp) {
            pli it = {product[pt[0]].second, pt[0]};
            s[0].insert(it);
            pt[0] += 1;
        }
        while (pt[1] < product.size() && product[pt[1]].first < tp + d[id]) {
            pli it = {product[pt[1]].second, pt[1]};
            s[1].erase(it);
            pt[1] += 1;
        }
        if (!s[0].empty()) {
            ll mn = s[0].begin()->first;
            ans[id] = std::min(ans[id], check(id, mn));
        }
        if (!s[1].empty()) {
            ll mn = s[1].begin()->first;
            ans[id] = std::min(ans[id], check(id, mn) + d[id] + tp);

        }
    }
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("0_input.txt", "r", stdin);
    // freopen("0_output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    // std::cin >> T;
    while (T--) {
        std::cin >> n;
        for (int i = 1; i <= n; ++i) std::cin >> p[i];
        for (int i = 1; i <= n; ++i) std::cin >> c[i];
        std::cin >> m;
        for (int i = 1; i <= m; ++i) {
            ans[i] = 1e18;
        }
        for (int i =1; i <= m; ++i) std::cin >> tp[i];
        for (int i =1; i <= m; ++i) std::cin >> tc[i];
        for (int i =1; i <= m; ++i) std::cin >> d[i];
        solve();
        for (int i = 1; i <= n; ++i) {
            std::swap(p[i], c[i]);
        }
        for (int i = 1; i <= m; ++i) {
            std::swap(tp[i], tc[i]);
        }
        solve();
        ll mn = 1e18;
        for (int i = 1; i <= n; ++i) {
            mn = std::min(mn, p[i] + c[i]);
        }
        for (int i = 1; i <= m; ++i) {
            ans[i] = std::min(ans[i], mn);
            std::cout << ans[i] << '\n';
        }
    }

    return 0;
}
