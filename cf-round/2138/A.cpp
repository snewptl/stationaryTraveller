#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <bitset>
#include <memory.h>
#include <assert.h>
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;
typedef double db;
typedef long double ldb;
const int maxn = 2e5 + 5;
const ll mod = 998244353;
ll x, k;
std::vector<int> vec;
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; std::cin >> T;
    while (T--) {
        std::cin >> k >> x;
        vec.clear();
        ll t1 = x, t2 = (1ll << (k + 1)) - x;
        while (t1 != t2) {
            if (t1 < t2) {
                t2 -= t1;
                t1 *= 2;
                vec.push_back(1);
            } else {
                t1 -= t2;
                t2 *= 2;
                vec.push_back(2);
            }
        }
        std::reverse(all(vec));
        std::cout << vec.size() << '\n';
        for (auto it : vec) std::cout << it << ' ';
        std::cout << '\n';
    }

    return 0;
}
