#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#define all(x) x.begin(), x.end()
typedef int64_t ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;
typedef double db;
typedef long double ldb;
const ll mod = 998244353;
const int maxn = 2e5 + 5;
const double eps = 1e-10;
int n, a[maxn];
ll dp[maxn];
bool check(ll limit) {
    std::set<pli> s;
    s.insert({0, 0});
    for (int i = 1; i <= n; ++i) dp[i] = 0;
    ll segmentLength = 0;
    int head = 0;
    for (int i = 1; i <= n; ++i) {
        // dp[i] = min{dp[j]} + a[i], 其中 j < i
        dp[i] = s.begin()->first + a[i];
        s.insert({dp[i], i});
        segmentLength += a[i];
        while (segmentLength > limit) {
            segmentLength -= a[head];
            if (head) 
                s.erase({dp[head - 1], head - 1});
            ++head;
        }
    }
    ll sum = 0;
    for (int i = n; i >= 1; --i) {
        if (dp[i] <= limit) return true;
        sum += a[i];
        if (sum > limit) return false;
    }
    return false;
}
ll dichotomy() {
    ll l = 0, r = 1e18, res = 1e18;
    while (l <= r) {
        ll mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid - 1;
            res = std::min(res, mid);
        } else {
            l = mid + 1;
        }
    }
    return res;
}
int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> n;
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
        }
        std::cout << dichotomy() << '\n';
        
    }

    return 0;
}
/*
0 1 2 3 4 5 6 7
    ^   ^ 
# 1 4 5 3 3 2 #

dp[0] = 0
dp[1] = dp[0] + 1 = 1
segment += 1

limit = 3 

a[1] < limit ->  dp[2] can get from dp[0]
dp[2] = min{dp[1], dp[0]} + a[2] = 4

segment += 4 -> segment = 5 > limit 
dp[3] = dp[2] + a[3] = 9

*/

/*

1
*/