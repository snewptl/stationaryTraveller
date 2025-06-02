#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <unordered_map> 
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;
typedef double db;
typedef long double ldb;
const int maxn = 2e5 + 5;
int n, a[5005];
std::unordered_map<int, int> dp;
int hash(std::vector<int> vec) {
    ll res = 1;
    for (auto it : vec) {
        res *= it;
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
        dp.clear();
        std::cin >> n;
        int all_gcd;
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
            if (i == 1) all_gcd = a[1];
            else all_gcd = std::__gcd(a[i], all_gcd);
        }
        std::vector<int> last, cur;
        int number_one = 0;
        for (int i = 1; i <= n; ++i) {
            a[i] /= all_gcd;
            if (a[i] == 1) {
                number_one += 1;
                continue;
            }
            std::vector<int> vec;
            for (int j = 2; j <= a[i]; ++j) {
                if (a[i] % j == 0) {
                    vec.push_back(j);
                }
                while(a[i] % j == 0) a[i] /= j; 
            }
            a[i] = hash(vec);
            dp[a[i]] = 0;
            last.push_back(a[i]);
        }
        if (number_one) {
            std::cout << n - number_one << '\n';
        } else {
            std::sort(all(last));
            last.resize(std::unique(all(last)) - last.begin());
            while (true) {
                if (dp.count(1)) {
                    std::cout << dp[1] + n - 1 << '\n';
                    break;
                }
                cur.clear();
                for (auto it : last) {
                    for (int i = 1; i <= n; ++i) {
                        int gcd = std::__gcd(it, a[i]);
                        int coast = dp[it] + 1;
                        if (!dp.count(gcd) || dp[gcd] > coast) {
                            cur.push_back(gcd);
                            dp[gcd] = coast;
                        }
                    }
                }
                last.clear();
                for (auto it : cur) last.push_back(it);
            }

        }
    }

    return 0;
}