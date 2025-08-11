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
int n;
int a[maxn], left[maxn], right[maxn], count;
std::vector<std::vector<int>> e;
std::vector<std::set<pii>> col;
ll ans;
namespace T {
    int lazy[maxn << 2], mx[maxn << 2], pos[maxn << 2];
    void push_up(int rt) {
        lazy[rt] = 0;
        if (mx[rt << 1] >= mx[rt << 1 | 1]) {
            pos[rt] = pos[rt << 1];
        } else {
            pos[rt] = pos[rt << 1 | 1];
        }
        mx[rt] = std::max(mx[rt << 1], mx[rt << 1 | 1]);
    }
    void push_dn(int rt, int l, int r) {
        if (l == r) {
            return;
        }
        if (lazy[rt]) {
            lazy[rt << 1] += lazy[rt];
            lazy[rt << 1 | 1] += lazy[rt];
            mx[rt << 1] += lazy[rt];
            mx[rt << 1 | 1] += lazy[rt];
            lazy[rt] = 0;
        }
    }
    void build(int rt, int l, int r) {
        if (l == r) {
            lazy[rt] = mx[rt] = 0;
            pos[rt] = l;
            return;
        }
        int mid = (l + r) / 2;
        build(rt << 1, l, mid);
        build(rt << 1 | 1, mid + 1, r);
        push_up(rt);
    }
    void add(int rt, int l, int r, int xl, int xr, int delta) {
        if (xl == l && xr == r) {
            mx[rt] += delta;
            lazy[rt] += delta;
            return;
        }
        int mid = (l + r) / 2;
        push_dn(rt, l, r);
        if (xl <= mid) add(rt << 1, l, mid, xl, std::min(xr, mid), delta);
        if (xr > mid) add(rt << 1 | 1, mid + 1, r, std::max(mid + 1, xl), xr, delta);
        push_up(rt);
    }
    pii query(int rt, int l, int r, int xl, int xr) {
        if (xl == l && xr == r) {
            return {mx[rt], pos[rt]};
        }
        int mid = (l + r) / 2;
        push_dn(rt, l, r);
        pii res1= {0, 0}, res2 = {0, 0};
        if (xl <= mid) res1 = query(rt << 1, l, mid, xl, std::min(xr, mid));
        if (xr > mid) res2 = query(rt << 1 | 1, mid + 1, r, std::max(xl, mid + 1), xr);
        if (res1.first >= res2.first) return res1;
        else return res2;
    }
}
void dfs(int u) {
    if (e[u].size() == 0) {
        left[u] = right[u] = ++count;
    } else {
        left[u] = n, right[u] = 0;
        for (auto v : e[u]) {
            dfs(v);
            left[u] = std::min(left[u], left[v]);
            right[u] = std::max(right[u], right[v]);
        }
    }
}
void solve(int u) {
    for (auto v : e[u]) {
        solve(v);
    }
    std::vector<pii> del;
    auto it = col[a[u]].lower_bound({left[u], 0});
    while (it != col[a[u]].end()) {
        if (it->first > right[u]) break;
        T::add(1, 1, count, it->first, it->second, -1);
        del.push_back({it->first, it->second});
        ++it;
    }
    T::add(1, 1, count, left[u], right[u], 1);
    for (auto it : del) {
        col[a[u]].erase(it);
    }
    col[a[u]].insert({left[u], right[u]});
    pii res1 = T::query(1, 1, count, left[u], right[u]), res2 = {0, 0}, res3 = {0, 0};
    int son = 0;
    for (auto v : e[u]) {
        if (left[v] <= res1.second && right[v] >= res1.second) {
            son = v;
            break;
        }
    }
    if (son == 0) son = u;
    pii seg1 = {left[u], left[son] - 1}, seg2 = {right[son] + 1, right[u]};
    if (seg1.first <= seg1.second) {
        res2 = T::query(1, 1, count, seg1.first, seg1.second);
    }
    if (seg2.first <= seg2.second) {
        res3 = T::query(1, 1, count, seg2.first, seg2.second);
    }
    if (res3.first > res2.first) res2 = res3;
    ans = std::max(1ll * res1.first * std::max(res2.first, 1), ans);
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
        e.clear();
        e.resize(n + 1);
        count = 0;
        ans = 0;
        col.clear();
        col.resize(n + 1);
        for (int i = 1; i < n; ++i) {
            int p;
            std::cin >> p;
            e[p].push_back(i + 1);
        }
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
        }
        dfs(1);
        T::build(1, 1, count);
        solve(1);
        std::cout << ans << '\n';
    }

    return 0;
}
// 15 : 47 - 18 : 11
