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
const int maxn = 3e5 + 5;
int n, k;
int a[maxn];
int cold[maxn], hot[maxn];
std::set<pli> s;
ll dp[maxn];
void solve() {
    dp[0] = cold[a[1]];
    s.insert({cold[a[1]], 0});
    ll add = 0;
    for (int i = 2; i <= n; ++i) {
        ll delta = (a[i] == a[i - 1] ? hot[a[i]] : cold[a[i]]);
        ll temp = 1e18;
        if (dp[a[i]] != 1e18) {
            temp = dp[a[i]] + add + hot[a[i]];
        }
        auto it = s.begin();
        if (it->second == a[i]) ++it;
        temp = std::min(temp, it->first + add + cold[a[i]]);
        if (dp[a[i - 1]] + add + delta > temp) {
            s.erase({dp[a[i - 1]], a[i - 1]});
            dp[a[i - 1]] = temp - add - delta;
            s.insert({dp[a[i - 1]], a[i - 1]});
        }
        add += delta;
    }
    std::cout << s.begin()->first + add << '\n';
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
        std::cin >> n >> k;
        s.clear();
        for (int i = 1; i <= k; ++i) dp[i] = 1e18;
        for (int i = 1; i <= n; ++i) std::cin >> a[i];
        for (int i = 1; i <= k; ++i) std::cin >> cold[i];
        for (int i = 1; i <= k; ++i) std::cin >> hot[i];
        solve();
    }

    return 0;
}
