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
int n, dp[maxn], ans[maxn];
pii a[maxn];
void swap(int x) {
    std::cout << "swap " << x << std::endl;
    std::swap(a[x], a[x + 1]);
}
int thr(int x) {
    std::cout << "throw " << x << std::endl;
    int res;
    std::cin >> res;
    return res;
}
void output() {
    std::cout << "! ";
    for (int i = 1; i <= n; ++i) {
        std::cout << ans[i] << ' ';
    }
    std::cout << std::endl;
}
int main() {
    #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> n;
        for (int i = 1; i <= n + 2; ++i) {
            a[i].first = 0;
            a[i].second = i;
            dp[i] = 0;
        }
        int res = thr(n - 1);
        if (res == 1) a[n - 1].first = 2;
        else a[n - 1].first = 1;
        swap(n - 1);
        dp[n] = 1;
        dp[n + 1] = 0;
        for (int i = n - 1; i >= 1; --i) {
            int res[3] = {0, dp[i + 1] + 1, dp[i + 2] + 1};
            if (res[1] != res[2]) {
                int cur = thr(i);
                if (cur == res[1]) a[i].first = 1;
                else {
                    a[i].first = 2;
                    assert(cur == res[2]);
                }
                dp[i] = dp[i + a[i].first] + 1;
            } else {
                swap(i);
                int cur = thr(i + 1);
                res[1] = dp[i + 1 + 1] + 1;
                res[2] = dp[i + 1 + 2] + 1;
                assert(res[1] != res[2]);
                if (cur == res[1]) a[i + 1].first = 1;
                else {
                    a[i + 1].first = 2;
                    assert(cur == res[2]);
                }
                dp[i + 1] = dp[i + 1 + a[i + 1].first] + 1;
                dp[i] = dp[i + a[i].first] + 1;
            }
        }
        for (int i = 1; i <= n; ++i) {
            ans[a[i].second] = a[i].first;
        }
        output();
    }

    return 0;
}

/*
. #
# .
# . . . . 
. # . . 
2 # . .
1 . . . 
. 1 . .

1 1 . . OK
2 1 . . NO

1 2 . . OK
2 2 . . OK


2 . . .

*/

/*
2 1 1 2
*/