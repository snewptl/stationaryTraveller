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
const int maxn = 3e5 + 5;
const ll mod = 998244353;
std::string s;
int count[maxn];
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
        std::cin >> s;
        int n = s.size();
        int add = 0;
        int ans = n + 1;
        count[n + 1] = 0;
        for (int i = 1; i <= n; ++i) {
            int x = s[i - 1] - '0';
            if (x == 4) add += 1;
        }
        for (int i = n; i >= 1; --i) {
            int x = s[i - 1] - '0';
            count[i] = count[i + 1];
            if (x == 2) count[i] += 1;
        }
        int pre = 0;
        for (int i = 1; i <= n; ++i) {
            int x = s[i - 1] - '0';
            if (x == 1 || x == 3) {
                pre += 1;
                if (pre) {
                    ans = std::min(ans, add + pre - 1 + count[i + 1]);
                }
            }
        }
        ans = std::min(ans, add + pre);
        if (!pre) ans = add;
        std::cout << ans << '\n';
    }

    return 0;
}

/*
12 32 
*/