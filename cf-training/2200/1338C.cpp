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
ll n;
ll f[4] = {0, 3, 1, 2};
ll dfs(ll dis, int dep) {
    if (dep == 0) return 0;
    ll cur = dis >> (dep - 2);
    return (f[cur] << (dep - 2)) + dfs(dis % (1ll << (dep - 2)), dep - 2);
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
        ll n;
        std::cin >> n;
        std::vector<int> vec;
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        if (n <= 3) std::cout << vec[n - 1] << '\n';
        else {
            ll row = (n - 1) / 3 + 1;
            ll cur = 0;
            std::vector<ll> temp(3, 0);
            for (int i = 0; ; i += 2) {
                if (cur + (1ll << i) >= row) {
                    temp[0] = (1ll << i) + row - cur - 1;
                    temp[2] = dfs(row - cur - 1, i) + (1ll << i) * 3;
                    temp[1] = temp[0] ^ temp[2];
                    std::cout << temp[(n - 1) % 3] << '\n';
                    break;
                }
                cur += (1ll << i);
            }

        }
    }

    return 0;
}

// 13 : 18 - 