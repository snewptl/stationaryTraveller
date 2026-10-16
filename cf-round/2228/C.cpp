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
ll a, A;
int n;
std::vector<int> vec;
int dig[20];
int sz = 0;
ll ans;
void dfs(int dep, ll cur, int type) {
    if (dep == sz + 1) {
        ans = std::min(ans, std::abs(cur - A));
        return;
    }
    int x = dig[dep];
    if (type == 0) {
        auto it = std::lower_bound(all(vec), x);
        if (it == vec.end()) {
            --it;
            dfs(dep + 1, cur * 10 + *it, -1);
        } else {
            auto pre = it, nxt = it;
            if (*it == x) {
                dfs(dep + 1, cur * 10 + *it, 0);
                ++nxt;
            }
            if (nxt != vec.end()) {
                dfs(dep + 1, cur * 10 + *nxt, 1);
            }
            if (pre != vec.begin()) {
                --pre;
                dfs(dep + 1, cur * 10 + *pre, -1);
            }
        }
    } else if (type == -1) {
        dfs(dep + 1, cur * 10 + vec.back(), type);
    } else {
        dfs(dep + 1, cur * 10 + vec[0], type);
    }
}
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
        std::cin >> A >> n;
        ans = 1e18;
        sz = -1;
        a = A;
        vec.clear();
        for (int i = 0; i < 18; ++i) {
            dig[i] = 0;
        }
        while (a) {
            sz += 1;
            dig[sz] = a % 10;
            a /= 10;
        }
        sz = 17;
        std::reverse(dig, dig + sz + 1);
        for (int i = 1; i <= n; ++i) {
            int x;
            std::cin >> x;
            vec.push_back(x);
        }
        for (int i = 0; i <= sz; ++i) {
            int type = 0;
            for (int j = 0; j < i; ++j) {
                if (dig[j]) type = -1;
            }
            dfs(i, 0, type);
        }
        std::cout << ans << '\n';
    }

    return 0;
}
