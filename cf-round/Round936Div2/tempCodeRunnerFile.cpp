#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <memory.h>
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;
typedef double db;
typedef long double ldb;
const int maxn = 2e5 + 5;
int n, q, a[maxn];
std::vector<pii> seg[maxn];
ll dp[maxn];
int pos[maxn];
ll res[maxn];
struct Fenwick {
    ll tree[maxn];
    int size;
    void reset(int n) {
        memset(tree, 0, sizeof(n + 1));
        size = n;
    }
    void add(int x, ll val) {
        while(x <= size) {
            tree[x] += val;
            x += lowbit(x);
        }
    }
    ll query(int l, int r) {
        return sum(r) - sum(l - 1);
    }
    ll sum(int x) {
        ll res = 0;
        while(x) {
            res += tree[x];
            x -= lowbit(x);
        }
        return res;
    }
    int lowbit(int x) {
        return x & (-x);
    }
}spike;
void initializeDP(int l) {
    dp[l] = 1;
    for (int x = a[l]; x <= spike.size; x += a[l]) {
        if (pos[x] < l) continue;
        spike.add(pos[x], dp[pos[x]]);
        for (int y = x * 2; y <= spike.size; y += x) {
            if (pos[y] < pos[x]) continue;
            dp[pos[y]] += dp[pos[x]];
        }
    }
    for (int x = a[l]; x <= spike.size; x += a[l]) {
        dp[pos[x]] = 0;
    }
}
int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> n >> q;
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
            pos[a[i]] = i;
        }
        spike.reset(n);
        for (int i = 1; i <= n; ++i) seg[i].clear();
        for(int i = 1; i <= q; ++i) {
            int l, r;
            std::cin >> l >> r;
            seg[l].push_back({r, i});
        }
        for (int l = n; l >= 1; --l) {
            initializeDP(l);
            for (auto [r, i] : seg[l]) {
                res[i] = spike.query(l, r);
            }
        }
        for (int i = 1; i <= q; ++i) {
            std::cout << res[i] << " ";
        }
        std::cout << '\n';

    }

    return 0;
}
