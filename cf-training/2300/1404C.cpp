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
int n, q;
int a[maxn];
int in_vec[maxn];
int fw[maxn];
std::pair<pii, int> que[maxn];
int ans[maxn];
int lowbit(int x) {
    return x & (-x);
}
void update(int x, int val) {
    for (int i = x; i <= n; i += lowbit(i)) {
        fw[i] += val;
    }
}
int get_sum(int x) {
    int res = 0;
    for (int i = x; i; i -= lowbit(i)) {
        res += fw[i];
    }
    return res;
}
namespace Pre {
    int fw[maxn];
    void update(int x, int val) {
        for (int i = x; i <= n; i += lowbit(i)) {
            fw[i] += val;
        }
    }
    int get_sum(int x) {
        int res = 0;
        for (int i = x; i; i -= lowbit(i)) {
            res += fw[i];
        }
        return res;
    }
    void init() {
        for (int i = 1; i <= n; ++i) {
            fw[i] = 0;
        }
        for (int i = 1; i <= n; ++i) {
            if (a[i] > i) continue;
            int l = 1, r = i, res = 0;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (get_sum(r) - get_sum(l - 1) >= i - a[i]) {
                    l = mid + 1;
                    res = mid;
                } else {
                    r = mid - 1;
                }
            }
            if (res) {
                update(res, 1);
            }
            in_vec[i] = res;
        }
    }
};
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
        fw[i] = 0;
    }

    for (int i = 1; i <= q; ++i) {
        int x, y;
        std::cin >> x >> y;
        que[i] = {{n - y, x + 1}, i};
    }
    std::sort(que + 1, que + q + 1);
    int end = n;
    for (int i = q; i >= 1; --i) {
        auto [y, x] = que[i].first;
        int id = que[i].second;
        while (end > y) {
            if (in_vec[end]) update(in_vec[end], -1);
            --end;
        }
        ans[id] = get_sum(y) - get_sum(x - 1);
    }
    for (int i = 1; i <= q; ++i) {
        std::cout << ans[i] << '\n';
    }
    
    return 0;
}
// 17 : 00 - 17 : 31
// 21 : 05 - 