#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;
typedef double db;
typedef long double ldb;
const int maxn = 2e5 + 5;
int n, q;
ll a[maxn], b[maxn];
ll k;
bool check(ll x) {
    ll remain = k - n;
    ll t = (remain > 0 ? n : k);
    for (int i = 1; i <= n; ++i) {
        b[i] = a[i];
    }
    if (remain > 0 && remain % 2 == 1) {
        if (a[n] > x) {
            b[n] = a[n] - 1;
            t = n - 1;
            --remain;
        } else if (a[n] == x) {
            b[n] = a[n];
            ++remain;
            t = n - 1;
        } else {
            return false;
        }
    }
    for (int i = 1; i <= t; ++i) {
        b[i] = a[i] + k - i + 1;
    }

    std::sort(b + 1, b + n + 1);
    if (b[1] < x) return false;
    if (remain <= 0) return true;
    for (int i = n; i >= 1; --i) {
        remain -= (b[i] - x) * 2;
    }
    return remain <= 0;
}
void solve() {
    ll l = -2e9, r = 2e9;
    ll ans = -2e9;
    while (l <= r) {
        ll mid = l + r >> 1;
        if (check(mid)) l = mid + 1, ans = mid;
        else r = mid - 1;
    }
    std::cout << ans << ' ';
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    // std::cin >> T;
    while (T--) {
        std::cin >> n >> q;
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
        }
        std::sort(a + 1, a + n + 1);
        while (q--) {
            std::cin >> k;      
            solve();
        }
    }

    return 0;
}
