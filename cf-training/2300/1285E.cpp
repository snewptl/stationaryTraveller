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
pii t[maxn << 2], lazy[maxn << 2];
int n;
pii seg[maxn];
std::vector<std::vector<int>> e; 
pii pre[maxn];
std::map<int, int> mp;
void build(int rt, int l, int r) {
    t[rt].first = t[rt].second = 0;
    lazy[rt] = {0, 0};
    if (l == r) {
        return;
    }
    int mid = (l + r) / 2;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
}
pii merge(pii cur, int new_val) {
    if (cur.first < new_val) {
        cur.second = cur.first;
        cur.first = new_val; 
    } else if (cur.first >= new_val) {
        cur.second = std::max(cur.second, new_val);
    }
    return cur;
}
pii merge(pii a, pii b) {
    if (a.first < b.first) std::swap(a, b);
    if (b.first != a.first) a.second = std::max(b.first, a.second);
    else a.second = std::max(a.second, b.second);
    return a;
}
void push_dn(int rt) {
    if (lazy[rt].first) {
        t[rt << 1] = merge(t[rt << 1], lazy[rt]);
        lazy[rt << 1] = merge(lazy[rt << 1], lazy[rt]);
        t[rt << 1 | 1] = merge(t[rt << 1 | 1], lazy[rt]);
        lazy[rt << 1 | 1] = merge(lazy[rt << 1 | 1], lazy[rt]);
        lazy[rt] = {0, 0};
    }
}
void update(int rt, int l, int r, int xl, int xr, int idx) {
    if (xl == l && xr == r) {
        t[rt] = merge(t[rt], idx);
        lazy[rt] = merge(lazy[rt], idx);
        return;
    }
    int mid = (l + r) / 2;
    push_dn(rt);
    if (xl <= mid) update(rt << 1, l, mid, xl, std::min(xr, mid), idx);
    if (xr > mid) update(rt << 1 | 1, mid + 1, r, std::max(xl, mid + 1), xr, idx);
    t[rt] = merge(t[rt << 1], t[rt << 1 | 1]);
}
pii query(int rt, int l, int r, int xl, int xr) {
    if (xl == l && xr == r) {
        return t[rt];
    }
    int mid = (l + r) / 2;
    pii res = {0, 0};
    push_dn(rt);
    if (xl <= mid) res = query(rt << 1, l, mid, xl, std::min(xr, mid));
    if (xr > mid) res = merge(res, query(rt << 1 | 1, mid + 1, r, std::max(mid + 1, xl), xr));
    return res;
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
        mp.clear();
        for (int i = 1; i <= n; ++i) {
            std::cin >> seg[i].first >> seg[i].second;
            mp[seg[i].first] = 1;
            mp[seg[i].second] = 1;
        }
        std::sort(seg + 1, seg + n + 1);

        int end = 0;
        for (auto [key, _] : mp) {
            mp[key] = ++end; 
        }
        e.clear();
        e.resize(n + 1);
        for (int i = 1; i <= n; ++i) {
            seg[i].first = mp[seg[i].first];
            seg[i].second = mp[seg[i].second];
        }
        build(1, 1, end);
        for (int i = 1; i <= n; ++i) {
            pre[i] = query(1, 1, end, seg[i].first, seg[i].second);
            e[pre[i].first].push_back(i);
            update(1, 1, end, seg[i].first, seg[i].second, i);
        }
        int res = 0, ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (pre[i].first == 0) res += 1;
        }
        for (int i = 1; i <= n; ++i) {
            if (pre[i].first == 0) res -= 1;
            for (auto j : e[i]) {
                if (pre[j].second == 0) res += 1; 
            }
            ans = std::max(ans, res);
            for (auto j : e[i]) {
                if (pre[j].second == 0) res -= 1; 
            }
            if (pre[i].first == 0) res += 1;
        }
        std::cout << ans << '\n';
    }

    return 0;
}
// 13 : 12 - 14 : 37