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
ll a[maxn], b[maxn];
ll A[maxn], B[maxn];
ll vis[maxn];
bool check(ll x) {
    for (int i = 1; i <= n; ++i) {
        a[i] = A[i];
        b[i] = B[i];
    }
    for (int i = 0; i < k; ++i) {
        vis[i] = 1;
    }
    int count = 0;
    for (int i = 1; i <= n; ++i) {
        ll cur = a[i] / b[i];
        while (cur < k - 1) {
            vis[cur] -= 1;
            a[i] += x;
            cur = a[i] / b[i];
            ++count;
            if (count > k) return false;
        }
    }
    for (int i = 0; i < k - 1; ++i) {
        if (i) vis[i] += vis[i - 1];
        if (vis[i] < 0) return false;
    }
    return true;
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("0_input.txt", "r", stdin);
    // freopen("0_output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        std::cin >> A[i];
    }
    for (int i = 1; i <= n; ++i) {
        std::cin >> B[i];
    }
    ll l = 0, r = 1e13, ans = -1;
    while (l <= r) {
        ll mid = (l + r) / 2;
        if (check(mid)) r = mid - 1, ans = mid;
        else l = mid + 1;
    }
    std::cout << ans << '\n';

    return 0;
}
// 17 : 36 - 18 : 26