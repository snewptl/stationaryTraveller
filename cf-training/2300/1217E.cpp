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
int n, m;
int a[maxn];
int p10[15];
int count[10][maxn << 2];
pii t[10][maxn << 2];
int sum(pii x) {
    return x.first + x.second;
}
pii merge(pii x, pii y) {
    if (x > y) std::swap(x, y);
    if (y.first < x.second) x.second = y.first;
    return x;
}
void push_up(int j, int rt) {
    t[j][rt] = merge(t[j][rt << 1], t[j][rt << 1 | 1]);
    count[j][rt] = count[j][rt << 1] + count[j][rt << 1 | 1];
}
std::vector<int> divid(int x) {
    std::vector<int> res(10, 0);
    for (int i = 9; i >= 0; --i) {
        res[i] = x / p10[i];
        x %= p10[i];
    }
    return res;
}
void build(int j, int rt, int l, int r) {
    t[j][rt] = {1e9, 1e9};
    count[j][rt] = 0;
    if (l == r) return;
    int mid = (l + r) / 2;
    build(j, rt << 1, l, mid);
    build(j, rt << 1 | 1, mid + 1, r);
}
void update(int j, int rt, int l, int r, int pos, int val, int delta) {
    if (l == r) {
        t[j][rt].first = val;
        if (delta == 1) {
            count[j][rt] = 1;
        } else {
            count[j][rt] = 0;
        }
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid) update(j, rt << 1, l, mid, pos, val, delta);
    else update(j, rt << 1 | 1, mid + 1, r, pos, val, delta);
    push_up(j, rt);
}
std::pair<pii, int> query(int j, int rt, int l, int r, int xl, int xr) {
    if (xl == l && xr == r) {
        return {t[j][rt], count[j][rt]};
    }
    int mid = (l + r) / 2;
    std::pair<pii, int> res = {{1e9, 1e9}, 0};
    if (xl <= mid) res = query(j, rt << 1, l, mid, xl, std::min(xr, mid));
    if (xr > mid) {
        auto temp = query(j, rt << 1 | 1, mid + 1, r, std::max(mid + 1, xl), xr);
        res.first = merge(res.first, temp.first);
        res.second += temp.second; 
    }
    return res;
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("0_input.txt", "r", stdin);
    // freopen("0_output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    p10[0] = 1;
    for (int i = 1; i < 10; ++i) {
        p10[i] = p10[i - 1] * 10;
    } 
    std::cin >> n >> m;
    for (int i = 0; i < 10; ++i) {
        build(i, 1, 1, n);
    }
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
        std::vector<int> vec = divid(a[i]);
        for (int j = 0; j < 10; ++j) {
            if (vec[j]) {
                update(j, 1, 1, n, i, a[i], 1);
            }
        }
    }
    
    for (int i = 1; i <= m; ++i) {
        int opt;
        std::cin >> opt;
        if (opt == 1) {
            int pos, x;
            std::cin >> pos >> x;
            std::vector<int> vec1 = divid(a[pos]), vec2 = divid(x);
            for (int j = 0; j < 10; ++j) {
                if (vec1[j] || vec2[j]) {
                    if (vec2[j]) update(j, 1, 1, n, pos, x, 1);
                    else update(j, 1, 1, n, pos, 1e9, -1);
                }
            }
            a[pos] = x;
        } else {
            int l, r;
            std::cin >> l >> r;
            int ans = 2e9, flag = 0;
            for (int j = 0; j < 10; ++j) {
                flag = 0;
                auto [res, count] = query(j, 1, 1, n, l, r);
                if (count > 1) {
                    flag = 1;
                    ans = std::min(ans, sum(res));
                }
            }
            if (ans == 2e9) ans = -1;
            std::cout << ans << '\n';
        }
    }

    return 0;
}
// 15 : 20 - 