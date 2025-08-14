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
int big_l[maxn], big_r[maxn];
int small_l[maxn], small_r[maxn][20];
ll sum[maxn][20];
ll ans;
int n, a[maxn];
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }

    std::vector<pii> vec;
    vec.push_back({n + 1, 0});
    for (int i = 1; i <= n; ++i) {
        while (vec.back().first < a[i]) {
            vec.pop_back();
        }
        big_l[i] = vec.back().second;
        vec.push_back({a[i], i});
    }
    vec.clear();
    vec.push_back({n + 1, n + 1});
    for (int i = n; i >= 1; --i) {
        while (vec.back().first < a[i]) {
            vec.pop_back();
        }
        big_r[i] = vec.back().second;
        vec.push_back({a[i], i});
    }

    vec.clear();
    vec.push_back({0, 0});
    for (int i = 1; i <= n; ++i) {
        while (vec.back().first > a[i]) {
            vec.pop_back();
        }
        small_l[i] = vec.back().second;
        vec.push_back({a[i], i});
    }
    vec.clear();
    vec.push_back({0, n + 1});
    for (int i = n; i >= 1; --i) {
        while (vec.back().first > a[i]) {
            vec.pop_back();
        }
        small_r[i][0] = vec.back().second;
        sum[i][0] = 1ll * (small_r[i][0] - i) * small_l[i];
        vec.push_back({a[i], i});
    }
    for (int j = 0; j < 20; ++j) {
        small_r[n + 1][j] = n + 1; 
    }
    for (int j = 1; j < 20; ++j) {
        for (int i = 1; i <= n; ++i) {
            small_r[i][j] = small_r[small_r[i][j - 1]][j - 1];
            sum[i][j] = sum[i][j - 1] + sum[small_r[i][j - 1]][j - 1];
        }
    }


    for (int i = 1; i <= n; ++i) {
        int l = big_l[i] + 1, r = big_r[i] - 1;
        ll res = i - l;
        int cur = i + 1;
        if (cur > r) {
            ans += res;
            continue;
        }
        for (int j = 19; j >= 0; --j) {
            if (small_r[cur][j] > r) continue;
            if (small_l[small_r[cur][j]] < l) continue;
            res += sum[cur][j];
            res -= 1ll * (small_r[cur][j] - cur) * (l - 1);
            cur = small_r[cur][j];
        }
        res += 1ll * (std::min(r + 1, small_r[cur][0]) - cur) * std::max(small_l[cur] - (l - 1), 0);
        ans += res;
    }
    std::cout << ans << '\n';

    return 0;
}
// 10 : 48 - 12 : 14
// 16 : 34 - 17 : 05
/*


*/