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
const int maxn = 2e3 + 5;
const ll mod = 998244353;
int n, p[maxn], q[maxn];
int from[maxn], to[maxn];
int t[maxn << 2];
void push_up(int rt) {
    t[rt] = std::min(t[rt << 1], t[rt << 1 | 1]);
}
void build(int rt, int l, int r) {
    if (l == r) {
        t[rt] = p[l];
        return;
    }
    int mid = (l + r) / 2;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    push_up(rt);
}
void update(int rt, int l, int r, int pos, int val) {
    if (l == r) {
        t[rt] = val;
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid) update(rt << 1, l, mid, pos, val);
    else update(rt << 1 | 1, mid + 1, r, pos, val);
    push_up(rt);
}
int query(int rt, int l, int r, int xl, int xr) {
    if (xl == l && xr == r) {
        return t[rt];
    }
    int mid = (l + r) / 2;
    int res = n + 1;
    if (xl <= mid) res = query(rt << 1, l, mid, xl, std::min(xr, mid));
    if (xr > mid) res = std::min(res, query(rt << 1 | 1, mid + 1, r, std::max(mid + 1, xl), xr));
    return res;
}
bool solve() {
    std::vector<pii> ans;
    build(1, 1, n);
    for (int i = 1; i <= n; ++i) {
        if (from[i] > to[i]) return false;
        int pos = from[i];
        while (pos != to[i]) {
            int min = query(1, 1, n, pos + 1, to[i]);
            int nxt = from[min];
            ans.push_back({pos, nxt});
            p[pos] = min;
            from[min] = pos;
            update(1, 1, n, pos, min);
            pos = nxt;
        }
        p[to[i]] = n + 1;
        update(1, 1, n, to[i], n + 1);
    }
    std::cout << "YES\n" << ans.size() << '\n';
    for (auto [a, b] : ans) {
        std::cout << a << ' ' << b << '\n'; 
    }
    return true;
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
        std::cin >> n;
        for (int i = 1; i <= n; ++i) {
            std::cin >> p[i];
            from[p[i]] = i;
        }
        for (int i = 1; i <= n; ++i) {
            std::cin >> q[i];
            to[q[i]] = i;
        }
        if (!solve()) std::cout << "NO\n";
    }

    return 0;
}
