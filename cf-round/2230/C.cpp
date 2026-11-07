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
ll c[maxn];
int n;
int main() {
    #ifndef ONLINE_JUDGE
    freopen("0_input.txt", "r", stdin);
    // freopen("0_output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> n;
        ll p = 0, remain = 0, ans = 0;
        ll one = 0, mxp = 0;
        for (int i = 1; i <= n; ++i) {
            std::cin >> c[i];
            if (c[i] == 1) one += 1;
            if (c[i] / 2) {
                ans += c[i];
                p += c[i] / 2  - 1;
                mxp = std::max(mxp, c[i]);
            } else remain += 1;
        }
        ans += std::min(remain, p);
        if (one) ans = std::max(ans, mxp + std::min(one, mxp / 2));
        if (ans < 3) ans = 0;
        std::cout <<  ans << '\n'; 
    }

    return 0;
}

/*
a a b b a a b b a a b b 

a b a a b b b

b b a b b a b b A
*/