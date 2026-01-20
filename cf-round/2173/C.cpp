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
int n, k;
int a[maxn];
std::map<int, int> mp, vis;
std::vector<int> vec;
bool solve() {
    for (auto [cur, _] : mp) {
        if (vis[cur]) continue;
        vec.push_back(cur);
        for (int i = cur * 2; i <= k; i += cur) {
            if (!mp[i]) return false;
            vis[i] = 1;
        }
    }
    return true;
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
        vec.clear();
        mp.clear();
        vis.clear();
        std::cin >> n >> k;
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
            mp[a[i]] = 1;
        }
        if (!solve()) std::cout << "-1\n";
        else {
            std::cout << vec.size() << '\n';
            for (auto it : vec) {
                std::cout << it << ' ';
            }
            std::cout << '\n';
        }

    }

    return 0;
}
