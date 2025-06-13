#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <assert.h>
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
int n;
int ask(int x) {
    int h;
    std::cout << "? " << x << std::endl;
    std::cin >> h;
    return h;
}
bool check(int x) {
    int h = ask(x);
    return h == 1;
}
int main() {
    #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    // std::cin >> T;
    while (T--) {
        std::cin >> n;
        int l = 1, r = 5e6, sum = 0, ans = 0;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (check(mid)) r = mid - 1, sum = mid;
            else l = mid + 1;
        }
        ans = sum;
        for (int i = 2; i <= n; ++i) {
            for (int j = sum - i + 1; j < sum; ++j) {
                if (j % i != 0) continue;
                int h = ask(j / i);
                if (h == i) ans = std::min(ans, j);
            }
        }
        std::cout << "! " << ans << std::endl;
    }

    return 0;
}


/*

(sum - (n - 1) + (w - 1)) / w * w < sum

(sum - n) // w < sum / w - 1

sum % w = remain

w > n > remain : sum / w - 小数部分 - 1
*/

/*
(sum - (n - 1) + (w - 1)) // w = h

sum - (h - 1) <= h * w

sum - ((sum - (n - 1) + (w - 1)) // w - 1)

sum - (sum - (n - 1) + (w - 1)) // w + 1

sum - (sum - n + w) // w + 1

sum - (sum - n) // w

(sum - n) // w >= 1

sum >= w + n

*/