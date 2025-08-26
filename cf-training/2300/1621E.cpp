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
int n, m;
int a[maxn];
std::vector<std::vector<int>> b;
std::vector<int> val;
pll divsion[maxn];
struct node {
    int lz, min;
}t[maxn << 2];
bool is_small(pll l, pll r) {
    return l.first * r.second < r.first * l.second;
}
ll up_floor(pll x) {
    return (x.first + x.second - 1) / x.second;
}
void push_up(int rt) {
    t[rt].min = std::min(t[rt << 1].min, t[rt << 1 | 1].min);
}
void push_dn(int rt) {
    if (t[rt].lz) {
        t[rt << 1].lz += t[rt].lz;
        t[rt << 1 | 1].lz += t[rt].lz;
        t[rt << 1].min += t[rt].lz;
        t[rt << 1 | 1].min += t[rt].lz;
        t[rt].lz = 0;
    }
}
void build(int rt, int l, int r) {
    t[rt].lz = 0;
    if (l == r) {
        t[rt].min = val[l];
        return;
    }
    int mid = (l + r) / 2;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    push_up(rt);
}
void update(int rt, int l, int r, int xl, int xr, int delta) {
    if (xl == l && xr == r) {
        t[rt].min += delta;
        t[rt].lz += delta;
        return;
    }
    push_dn(rt);
    int mid = (l + r) / 2;
    if (xl <= mid) update(rt << 1, l, mid, xl, std::min(xr, mid), delta);
    if (xr > mid) update(rt << 1 | 1, mid + 1, r, std::max(xl, mid + 1), xr, delta);
    push_up(rt);
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
        std::cin >> n >> m;
        std::vector<pll> vec;
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
            vec.push_back({a[i], 1});
        }
        b.resize(n + 1);
        for (int i = 1; i <= m; ++i) {
            int sz; std::cin >> sz;
            b[i].resize(sz + 1);
            ll sum = 0;
            for (int j = 1; j <= sz; ++j) {
                std::cin >> b[i][j];
                sum += b[i][j];
            }
            for (int j = 1; j <= sz; ++j) {
                ll x = sum - b[i][j], y = sz - 1;
                ll d = std::__gcd(x, y);
                vec.push_back({x / d, y / d});
            }
            ll x = sum, y = sz;
            ll d = std::__gcd(x, y);
            vec.push_back({x / d, y / d});
            divsion[i] = {x / d, y / d};
        }
        std::sort(all(vec), is_small);
        vec.resize(std::unique(all(vec)) - vec.begin());
        val.clear();
        val.resize(vec.size());
        for (int i = 1; i <= n; ++i) {
            pll cur = {a[i], 1};
            auto it = std::lower_bound(all(vec), cur, is_small) - vec.begin();
            val[it] += 1;
        }
        for (int i = 1; i <= m; ++i) {
            pll cur = divsion[i];
            auto it = std::lower_bound(all(vec), cur, is_small) - vec.begin();
            val[it] -= 1;
        }
        for (int i = vec.size() - 2; i >= 0; --i) {
            val[i] += val[i + 1];
        }
        build(1, 0, vec.size() - 1);
        for (int i = 1; i <= m; ++i) {
            pll cur = divsion[i];
            auto it = std::lower_bound(all(vec), cur, is_small) - vec.begin();
            update(1, 0, vec.size() - 1, 0, it, 1);
            ll sum = 0;
            for (int j = 1; j < b[i].size(); ++j) {
                sum += b[i][j];
            }
            for (int j = 1; j < b[i].size(); ++j) {
                ll x = sum - b[i][j], y = b[i].size() - 2;
                ll d = std::__gcd(x, y);
                x /= d, y /= d;
                pll temp = {x, y};
                auto that = std::lower_bound(all(vec), temp, is_small) - vec.begin();
                update(1, 0, vec.size() - 1, 0, that, -1);
                if (t[1].min < 0) std::cout << '0';
                else std::cout << '1';
                update(1, 0, vec.size() - 1, 0, that, 1);
            }
            update(1, 0, vec.size() - 1, 0, it, -1);
        }
        std::cout << '\n';
    }

    return 0;
}
// 19 : 24 - 