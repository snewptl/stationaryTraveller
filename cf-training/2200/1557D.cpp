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
const int maxn = 3e5 + 5;
const ll mod = 998244353;
struct node {
    int max;
    int idx;
    int lazy;
    int left, right; 
};
int n, m;
std::vector<std::vector<pii>> vec;
int fa[maxn], vis[maxn];
std::vector<node> t;
int count;
void push_down(int rt) {
    if (t[rt].lazy) {
        t[t[rt].left].max = t[rt].max;
        t[t[rt].left].idx = t[rt].idx;
        t[t[rt].left].lazy = t[rt].lazy;
        t[t[rt].right].max = t[rt].max;
        t[t[rt].right].idx = t[rt].idx;
        t[t[rt].right].lazy = t[rt].lazy;
        t[rt].lazy = 0;
    }
}
pii query(int rt, int l, int r, int xl, int xr) {
    int mid = (l + r) >> 1;
    if (xl == l && xr == r) {
        return {t[rt].max, t[rt].idx};
    }
    if (!t[rt].left) {
        node left_son;
        left_son.lazy = t[rt].lazy;
        left_son.max = t[rt].max;
        left_son.idx = t[rt].idx;
        left_son.left = 0;
        left_son.right = 0;
        t[rt].left = ++count;
        t.push_back(left_son);
    }
    if (!t[rt].right) {
        node right_son;
        right_son.lazy = t[rt].lazy;
        right_son.max = t[rt].max;
        right_son.idx = t[rt].idx;
        right_son.left = 0;
        right_son.right = 0;
        t[rt].right = ++count;
        t.push_back(right_son);
    }
    push_down(rt);
    pii res = {0, 0};
    if (xl <= mid) res = query(t[rt].left, l, mid, xl, std::min(xr, mid));
    if (xr > mid) {
        pii temp = query(t[rt].right, mid + 1, r, std::max(xl, mid + 1), xr);
        if (temp.first > res.first) res = temp;
    } 
    return res;
}
void update(int rt, int l, int r, int xl, int xr, int val, int idx) {
    int mid = (l + r) >> 1;
    if (xl == l && xr == r) {
        t[rt].lazy = 1;
        t[rt].max = val;
        t[rt].idx = idx;
        return;
    }
    push_down(rt);
    if (xl <= mid) update(t[rt].left, l, mid, xl, std::min(xr, mid), val, idx);
    if (xr > mid) update(t[rt].right, mid + 1, r, std::max(xl, mid + 1), xr, val, idx);
    if (t[t[rt].left].max > t[rt].max) {
        t[rt].max = t[t[rt].left].max;
        t[rt].idx = t[t[rt].left].idx;
    }
    if (t[t[rt].right].max > t[rt].max) {
        t[rt].max = t[t[rt].right].max;
        t[rt].idx = t[t[rt].right].idx;
    }
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> m;
    vec.resize(n + 1);
    for (int i = 1; i <= m; ++i) {
        int id, l, r;
        std::cin >> id >> l >> r;
        vec[id].push_back({l, r});
    }
    t.resize(2);
    int root = ++count;
    t[root].max = 0, t[root].idx = 0;
    pii ans = {0, 0};
    for (int i = 1; i <= n; ++i) {
        pii res = {0, 0};
        for (auto [l, r] : vec[i]) {
            auto [val, pos] = query(root, 1, 1e9, l, r);
            if (val > res.first) {
                res.first = val;
                res.second = pos;
            }
        }
        fa[i] = res.second;
        if (ans.first < res.first + 1) ans.first = res.first + 1, ans.second = i;
        for (auto [l, r] : vec[i]) {
            update(root, 1, 1e9, l, r, res.first + 1, i);
        }
    }
    std::cout << n - ans.first << '\n';
    int cur = ans.second;
    while (cur) {
        vis[cur] = 1;
        cur = fa[cur];
    }
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) std::cout << i << ' ';
    }
    std::cout << '\n';

    return 0;
}
