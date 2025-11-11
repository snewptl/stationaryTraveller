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
struct tree_node {
    ll lazy[2];
    ll sum[2];
    ll vis_num;
}t[maxn << 2];
int n, p[maxn], rank[maxn];
void push_dn(int rt, int l, int r) {
    int mid = (l + r) / 2;
    for (int i = 0; i < 2; ++i) {
        if (t[rt].lazy[i]) {
            t[rt << 1].lazy[i] += t[rt].lazy[i];
            t[rt << 1].sum[i] += t[rt].lazy[i] * (mid - l + 1 - t[rt << 1].vis_num);
            t[rt << 1 | 1].lazy[i] += t[rt].lazy[i];
            t[rt << 1 | 1].sum[i] += t[rt].lazy[i] * (r - mid - t[rt << 1 | 1].vis_num);             
            t[rt].lazy[i] = 0;
        }
    }
}
void push_up(int rt) {
    for (int i = 0; i < 2; ++i) {
        t[rt].sum[i] = t[rt << 1].sum[i] + t[rt << 1 | 1].sum[i];
        t[rt].vis_num = t[rt << 1].vis_num + t[rt << 1 | 1].vis_num;
    }
}
tree_node query(int rt, int l, int r, int pos) {
    if (l == r) {
        return t[rt];
    }
    push_dn(rt, l, r);
    int mid = (l + r) / 2;
    if (pos <= mid) return query(rt << 1, l, mid, pos);
    else return query(rt << 1 | 1, mid + 1, r, pos);
}
void update(int rt, int l, int r, int xl, int xr, int type) {
    if (l == xl && r == xr) {
        t[rt].lazy[type] += 1;
        t[rt].sum[type] += r - l + 1 - t[rt].vis_num;
        return;
    }
    push_dn(rt, l, r);
    int mid = (l + r) / 2;
    if (xl <= mid) update(rt << 1, l, mid, xl, std::min(xr, mid), type);
    if (xr > mid) update(rt << 1 | 1, mid + 1, r, std::max(xl, mid + 1), xr, type);
    push_up(rt);
}
void disable(int rt, int l, int r, int pos) {
    if (l == r) {
        t[rt].vis_num = 1;
        for (int i = 0; i < 2; ++i) {
            t[rt].lazy[i] = t[rt].sum[i] = 0;
        }
        return;
    }
    push_dn(rt, l, r);
    int mid = (l + r) / 2;
    if (pos <= mid) disable(rt << 1, l, mid, pos);
    else disable(rt << 1 | 1, mid + 1, r, pos);
    push_up(rt);
}
int get_mid(int rt, int l, int r, int tot) {
    if (l == r) {
        return l;
    }
    push_dn(rt, l, r);
    int mid = (l + r) / 2;
    if (t[rt << 1].vis_num >= tot) return get_mid(rt << 1, l, mid, tot);
    else return get_mid(rt << 1 | 1, mid + 1, r, tot - t[rt << 1].vis_num);
}
ll get_sum(int rt, int l, int r, int xl, int xr, int type) {
    if (l == xl && r == xr) {
        return t[rt].sum[type];
    }
    push_dn(rt, l, r);
    int mid = (l + r) / 2;
    ll res = 0;
    if (xl <= mid) res += get_sum(rt << 1, l, mid, xl, std::min(xr, mid), type);
    if (xr > mid) res += get_sum(rt << 1 | 1, mid + 1, r, std::max(xl, mid + 1), xr, type);
    return res;
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("0_input.txt", "r", stdin);
    // freopen("0_output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        std::cin >> p[i];
        rank[p[i]] = i;
    }
    ll inv = 0;
    for (int i = 1; i <= n; ++i) {
        int pos = rank[i];
        tree_node res = query(1, 1, n, pos);
        inv += res.sum[1];
        disable(1, 1, n, pos);
        update(1, 1, n, 1, pos, 1);
        update(1, 1, n, pos, n, 0);
        int mid = get_mid(1, 1, n, (i + 1) / 2);
        // std::cout << "$$$" <<  get_sum(1, 1, n, 1, mid, 0) << ' ' << get_sum(1, 1, n, mid, n, 1) << '\n';
        ll ans = inv + get_sum(1, 1, n, 1, mid, 0) + get_sum(1, 1, n, mid, n, 1);
        std::cout << ans << ' ';
    }
    std::cout << '\n';
    return 0;
}
// 16 : 56 - 17 : 23
// 19 : 07 - 19 : 53