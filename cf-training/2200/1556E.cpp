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
const int maxn = 1e5 + 5;
const ll mod = 998244353;
int n, q;
ll a[maxn], b[maxn];
struct node {
    ll mx, mn, sum;
}t[maxn << 2];
node merge(node left, node right) {
    node res;
    res.mx = std::max(left.mx, right.mx + left.sum);
    res.mn = std::min(left.mn, right.mn + left.sum);
    res.sum = left.sum + right.sum;
    return res;
}
void build(int rt, int l, int r) {
    int mid = (l + r) >> 1;
    if (l == r) {
        t[rt].mx = t[rt].mn = t[rt].sum = b[l] - a[l];
        return;
    }
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    t[rt] = merge(t[rt << 1], t[rt << 1 | 1]);
}
node query(int rt, int l, int r, int xl, int xr) {
    int mid = (l + r) >> 1;
    if (xl == l && xr == r) {
        return t[rt];
    }
    if (xl <= mid) {
        node left = query(rt << 1, l, mid, xl, std::min(mid, xr));
        if (xr > mid) {
            node right = query(rt << 1 | 1, mid + 1, r, std::max(mid + 1, xl), xr);
            node res = merge(left, right);
            return res;
        } else return left;
    } else return query(rt << 1 | 1, mid + 1, r, std::max(xl, mid + 1), xr);
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        std::cin >> b[i];
    }
    build(1, 1, n);
    for (int i = 1; i <= q; ++i) {
        int l, r;
        std::cin >> l >> r;
        node res = query(1, 1, n, l, r);
        if (res.mn == 0 && res.sum == 0) std::cout << res.mx << '\n';
        else std::cout << "-1\n";
    }
    
    return 0;
}

// 22 : 45 - 23 : 35