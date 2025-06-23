#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <bitset>
#include <memory.h>
#include <assert.h>
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;
typedef double db;
typedef long double ldb;
const int maxn = 2e5 + 5;
const ll mod = 998244353;
int n, q;
int a[maxn];
struct tree_node {
    int left_len, left_element;
    int right_len, right_element;
    int flag;
    ll sum;
}t[maxn << 2];
tree_node merge(tree_node x, tree_node y) {
    tree_node res = {0, 0, 0, 0, 0, 0};
    res.left_element = x.left_element;
    res.right_element = y.right_element;
    res.flag = x.flag & y.flag;
    res.sum = x.sum + y.sum;
    if (x.right_element <= y.left_element) {
        if (x.flag) res.left_len = x.left_len + y.left_len;
        else res.left_len = x.left_len;
        if (y.flag) res.right_len = x.right_len + y.right_len;
        else res.right_len = y.right_len;
        if (!x.flag && !y.flag) {
            ll len = x.right_len + y.left_len;
            res.sum += (len + 1) * len / 2;
        }
    } else {
        res.flag = 0;
        res.left_len = x.left_len;
        res.right_len = y.right_len;
        if (!x.flag) {
            ll len = x.right_len;
            res.sum += len * (len + 1) / 2;
        }
        if (!y.flag) {
            ll len = y.left_len;
            res.sum += len * (len + 1) / 2;
        }
    }
    return res;
}
void push_up(int rt) {
    t[rt] = merge(t[rt << 1], t[rt << 1 | 1]);
}
void build(int rt, int l, int r) {
    int mid = (l + r) >> 1;
    if (l == r) {
        t[rt].left_element = t[rt].right_element = a[l];
        t[rt].left_len = t[rt].right_len = 1;
        t[rt].flag = 1;
        t[rt].sum = 0;
        return ;
    }
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    push_up(rt);
}
void update(int rt, int l, int r, int pos, int val) {
    int mid = (l + r) >> 1;
    if (l == r) {
        t[rt].left_element = t[rt].right_element = val;
        return;
    }
    if (pos <= mid) update(rt << 1, l, mid, pos, val);
    else update(rt << 1 | 1, mid + 1, r, pos, val);
    push_up(rt);
}
tree_node query(int rt, int l, int r, int xl, int xr) {
    int mid = (l + r) / 2;
    if (xl == l && xr == r) {
        return t[rt];
    }
    tree_node left_son, right_son;
    int has_left = 0, has_right = 0;
    if (xl <= mid) {
        has_left = 1;
        left_son = query(rt << 1, l, mid, xl, std::min(xr, mid));
    }
    if (xr > mid) {
        has_right = 1;
        right_son = query(rt << 1 | 1, mid + 1, r, std::max(xl, mid + 1), xr);
    }
    tree_node res;
    if (has_left) {
        if (has_right) res = merge(left_son, right_son);
        else res = left_son;
    } else res = right_son;
    return res;
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> q;
    for (int i = 1; i <= n; ++i) std::cin >> a[i];
    build(1, 1, n);
    for (int i = 1; i <= q; ++i) {
        int opt, x, y;
        std::cin >> opt >> x >> y;
        if (opt == 1) {
            update(1, 1, n, x, y);
        } else {
            tree_node cur = query(1, 1, n, x, y);
            ll len = cur.left_len;
            ll ans = cur.sum;
            ans += (len + 1) * len / 2;
            if (!cur.flag) {
                len = cur.right_len;
                ans += (len + 1) * len / 2;
            }
            std::cout << ans << '\n';
        }

    }

    return 0;
}


/*
    t[rt].left_element = t[rt << 1].left_element;
    t[rt].right_element = t[rt << 1 | 1].right_element;
    t[rt].flag = t[rt << 1].flag & t[rt << 1 | 1].flag;
    t[rt].sum = t[rt << 1].sum + t[rt << 1 | 1].sum;
    if (t[rt << 1].right_element <= t[rt << 1 | 1].left_element) {
        if (t[rt << 1].flag) {
            t[rt].left_len = t[rt << 1].left_len + t[rt << 1 | 1].left_len;
        } else {
            t[rt].left_len = t[rt << 1].left_len;
        }
        if (t[rt << 1 | 1].flag) {
            t[rt].right_len = t[rt << 1].right_len + t[rt << 1 | 1].right_len;
        } else {
            t[rt].right_len = t[rt << 1 | 1].right_len;
        }
        if (!t[rt << 1].flag && !t[rt << 1 | 1].flag) {
            ll len = t[rt << 1].right_len + t[rt << 1 | 1].left_len;
            t[rt].sum += len * (len + 1) / 2;
        }
    } else {
        t[rt].left_len = t[rt << 1].left_len;
        t[rt].right_len = t[rt << 1 | 1].right_len;
        if (!t[rt << 1].flag) {
            ll len = t[rt << 1].right_len;
            t[rt].sum += len * (len + 1) / 2;
        }
        if (!t[rt << 1 | 1].flag) {
            ll len = t[rt << 1 | 1].left_len;
            t[rt].sum += len * (len + 1) / 2;
        }
    }
*/
// 14 : 30 - 15 : 09