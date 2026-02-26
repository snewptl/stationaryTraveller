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
int n, k;
int node[maxn][6];
int mask;
struct tree_node {
    int max[32];
    int sum;
    tree_node() {
        for (int i = 0; i <= mask; ++i) max[i] = -1e9;
        sum = -1e9;
    }
}t[maxn << 2];
int cal(int i, int t) {
    int res = 0;
    for (int j = 0; j < k; ++j) {
        if ((1 << j) & t) {
            res -= node[i][j];
        } else {
            res += node[i][j];
        }
    }
    return res;
}
void push_up(int rt) {
    for (int i = 0; i <= mask; ++i) {
        t[rt].max[i] = std::max(t[rt << 1].max[i], t[rt << 1 | 1].max[i]);
    }
    t[rt].sum = -1e9;
    for (int i = 0; i <= mask; ++i) {
        t[rt].sum = std::max(t[rt].max[i] + t[rt].max[i ^ mask], t[rt].sum);
    }
}
void build(int rt, int l, int r) {
    if (l == r) {
        for (int i = 0; i <= mask; ++i) {
            int res = cal(l, i);
            t[rt].max[i] = res;
        }
        t[rt].sum = -1e9;
        for (int i = 0; i <= mask; ++i) {
            t[rt].sum = std::max(t[rt].max[i] + t[rt].max[i ^ mask], t[rt].sum);
        }
        return;
    }
    int mid = (l + r) / 2;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    push_up(rt);
}
void update(int rt, int l, int r, int pos) {
    if (l == r) {
        for (int i = 0; i <= mask; ++i) {
            int res = cal(l, i);
            t[rt].max[i] = res;
        }
        t[rt].sum = -1e9;
        for (int i = 0; i <= mask; ++i) {
            t[rt].sum = std::max(t[rt].max[i] + t[rt].max[i ^ mask], t[rt].sum);
        }
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid) update(rt << 1, l, mid, pos);
    else update(rt << 1 | 1, mid + 1, r, pos);
    push_up(rt);
}
tree_node merge(tree_node x, tree_node y) {
    tree_node z;
    for (int i = 0; i <= mask; ++i) {
        z.max[i] = std::max(x.max[i], y.max[i]);
    }
    for (int i = 0; i <= mask; ++i) {
        z.sum = std::max(z.sum, z.max[i] + z.max[i ^ mask]);
    }
    return z;
}
tree_node query(int rt, int l, int r, int xl, int xr) {
    if (l == xl && r == xr) {
        return t[rt];
    }
    int mid = (l + r) / 2;
    tree_node res;
    if (xl <= mid) res = query(rt << 1, l, mid, xl, std::min(mid, xr));
    if (xr > mid) res = merge(res, query(rt << 1 | 1, mid + 1, r, std::max(xl, mid + 1), xr));
    return res;
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("0_input.txt", "r", stdin);
    // freopen("0_output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> k;
    mask = (1 << k) - 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < k; ++j) {
            std::cin >> node[i][j];
        }
    }
    build(1, 1, n);
    int q; std::cin >> q;
    while (q--) {
        int opt;
        std::cin >> opt;
        if (opt == 1) {
            int pos; std::cin >> pos;
            for (int i = 0; i < k; ++i) {
                std::cin >> node[pos][i];
            }
            update(1, 1, n, pos);
        } else {
            int l, r;
            std::cin >> l >> r;
            std::cout << query(1, 1, n, l, r).sum << '\n';
        }
    }

    return 0;
}
