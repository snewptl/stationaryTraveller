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
const int maxn = 1e6 + 5;
const ll mod = 998244353;
int n, m;
std::map<int, std::vector<int>> pos;
std::map<int, int> count;
int a[maxn], b[maxn], temp[maxn];
struct node {
    int lz, min;
}t[maxn << 2];
ll ans;
void push_up(int rt) {
    t[rt].min = std::min(t[rt << 1].min, t[rt << 1 | 1].min);
}
void push_down(int rt) {
    if (t[rt].lz) {
        t[rt << 1].lz += t[rt].lz;
        t[rt << 1].min += t[rt].lz;
        t[rt << 1 | 1].lz += t[rt].lz;
        t[rt << 1 | 1].min += t[rt].lz;
        t[rt].lz = 0;
    }
}
void build(int rt, int l, int r) {
    t[rt].lz = 0;
    if (l == r) {
        t[rt].min = l;
        return;
    }
    int mid = (l + r) / 2;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    push_up(rt);
}
void update(int rt, int l, int r, int xl, int xr, int delta) {
    if (xl == l && xr == r) {
        t[rt].lz += delta;
        t[rt].min += delta;
        return;
    }
    push_down(rt);
    int mid = (l + r) / 2;
    if (xl <= mid) update(rt << 1, l, mid, xl, std::min(xr, mid), delta);
    if (xr > mid) update(rt << 1 | 1, mid + 1, r, std::max(mid + 1, xl), xr, delta);
    push_up(rt);
}
void count_inv(int l, int r) {
    int mid = (l + r) / 2;
    if (l == r) {
        return;
    }
    count_inv(l, mid);
    count_inv(mid + 1, r);
    int i = l, j = mid + 1, start = l;
    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) {
            temp[start++] = a[i];
            ++i;
            ans += j - (mid + 1);
        } else {
            temp[start++] = a[j];
            ++j;
        }
    }
    while (i <= mid) {
        temp[start++] = a[i];
        ++i;
        ans += r - mid;
    }
    while (j <= r) {
        temp[start++] = a[j];
        ++j;
    }
    for (int t = l; t <= r; ++t) {
        a[t] = temp[t];
    }
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
        pos.clear();
        count.clear();
        ans = 0;
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
            pos[a[i]].push_back(i);
        }
        count_inv(1, n);
        for (int i = 1; i <= m; ++i) {
            std::cin >> b[i];
            count[b[i]] += 1;
        }
        build(1, 0, n);
        auto ptr = pos.begin();
        bool last_used = 0;
        for (auto [val, num] : count) {
            while(ptr != pos.end() && ptr->first < val) {
                for (auto p : ptr->second) {
                    if (last_used) {
                        update(1, 0, n, 0, p - 1, 1);
                    } else {
                        update(1, 0, n, 0, n, -1);
                        update(1, 0, n, 0, p - 1, 2);
                    }
                }
                last_used = 0;
                ++ptr;
            }
            if (ptr != pos.end() && ptr->first == val) {
                for (auto p : ptr->second) {
                    update(1, 0, n, 0, n, -1);
                    update(1, 0, n, 0, p - 1, 1);
                    last_used = 1;
                }
            } else {
                last_used = 0;
            }
            ans += 1ll * t[1].min * num;
        }
        std::cout << ans << '\n';
    }

    return 0;
}
// 10 : 30 - 11 : 30
