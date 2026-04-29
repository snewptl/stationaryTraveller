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
int n;
int a[maxn];
struct node {
    int lz;
    int min;
}t[maxn << 2];
int all[1000000 + 5];
void push_dn(int rt) {
    if (t[rt].lz) {
        int lz = t[rt].lz;
        t[rt].lz = 0;
        t[rt << 1].lz += lz;
        t[rt << 1].min += lz;
        t[rt << 1 | 1].lz += lz;
        t[rt << 1 | 1].min += lz;
    }
}
void push_up(int rt) {
    t[rt].min = std::min(t[rt << 1].min, t[rt << 1 | 1].min);
}
void build(int rt, int l, int r) {
    int mid = (l + r) / 2;
    t[rt].lz = 0;
    if (l == r) {
        t[rt].min = 0;
        return;
    }
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    push_up(rt);
}
void update(int rt, int l, int r, int xl, int xr, int delta) {
    int mid = (l + r) / 2;
    if (xl == l && xr == r) {
        t[rt].lz += delta;
        t[rt].min += delta;
        return;
    }
    push_dn(rt);
    if (xl <= mid) update(rt << 1, l, mid, xl, std::min(xr, mid), delta);
    if (xr > mid) update(rt << 1 | 1, mid + 1, r, std::max(xl, mid + 1), xr, delta);
    push_up(rt);
}
int query(int rt, int l, int r, int xl, int xr) {
    if (xr < xl) return 0;
    int mid = (l + r) / 2;
    if (xl == l && xr == r) {
        return t[rt].min;
    }
    push_dn(rt);
    int min = 1e9;
    if (xl <= mid) min = std::min(min, query(rt << 1, l, mid, xl, std::min(xr, mid)));
    if (xr > mid) min = std::min(min, query(rt << 1 | 1, mid + 1, r, std::max(xl, mid + 1), xr));
    return min;
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
        build(1, 0, n);
        int last = -1;
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
            all[a[i]] += 1;
            if (a[i] == last && all[a[i]] == 1) {
                update(1, 0, n, 0, a[i], 1);
            } else {
                update(1, 0, n, 0, std::min((a[i] - 1) / 2, n), 1);
            }
            while (query(1, 0, n, 0, last) >= 0) {
                last += 1;
                update(1, 0, n, 0, last, -1);
                if (all[last]) {
                    update(1, 0, n, 0, (last - 1) / 2, -1);
                    update(1, 0, n, 0, last, 1);
                }
            }
            std::cout << last << ' ';
        }
        std::cout << '\n';
        for (int i = 1; i <= n; ++i) {
            all[a[i]] = 0;
        }
    }

    return 0;
}
