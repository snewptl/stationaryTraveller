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
int n, a[maxn];
std::map<int, int> mp;
int mx = 0;
int LCM(int x, int y) {
    return x / std::__gcd(x, y) * y;
}
int checkResult(int x) {
    int cur = 0, lcm = 1;
    if (mp.count(x)) return 0;
    for (int j = 1; j <= n; ++j) {
        if (x % a[j] == 0) {
            cur ++;
            lcm = LCM(lcm, a[j]);
        }
    }
    return lcm == x ? cur : 0; 
}
int solve() {
    for (int i = 1; i <= n; ++i) {
        if (mx % a[i] != 0) {
            return n;
        }
    }
    int res = 0;
    for (int i = 1; i * i <= mx; ++i) {
        if (mx % i != 0) continue; 
        res = std::max(std::max(checkResult(i), checkResult(mx / i)), res);
    }

    return res;
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
        std::cin >> n;
        mx = 0;
        mp.clear();
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
            mx = std::max(mx, a[i]);
            mp[a[i]] ++;
        }
        std::cout << solve() << '\n';
    }

    return 0;
}
