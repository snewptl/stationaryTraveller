#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <assert.h>
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;
typedef double db;
typedef long double ldb;
const int maxn = 2e5 + 5;
int n, k, x;
int vis[maxn];
std::vector<std::vector<int>> vec;

bool solve() {
    int count[30];
    for (int i = 0; i < 30; ++i) count[i] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 30; ++j) {
            if ((1 << j) & i) count[j] += 1;
        }
    }
    for (int i = 0; i < 30; ++i) {
        if ((1 << i) & x) count[i] -= k;
        if (count[i] < 0 || count[i] % 2) return false;
    }
    int cur = 1;
    for (int i = 1; i <= k; ++i) {
        while (vis[cur] || (cur ^ x) > n) ++cur;
        assert(cur <= n);
        vis[cur] = vis[cur ^ x] = 1;
        vec[i].push_back(cur);
        if (cur ^ x) vec[i].push_back(cur ^ x); 
    }

    for (int i = n; i >= 1; --i) {
        if (vis[i]) continue;
        vec[1].push_back(i);
    }
    return true;
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
        std::cin >> n >> k >> x;
        vec.clear();
        vec.resize(k + 1);
        for (int i = 1; i <= n; ++i) {
            vis[i] = 0;
        }
        if (solve()) {
            std::cout <<  "YES\n";
            for (int i = 1; i <= k; ++i) {
                std::cout << vec[i].size() << ' ';
                for (auto it : vec[i]) {
                    std::cout << it << ' ';
                }
                std::cout << '\n';
            }
        } else {
            std::cout << "NO\n";
        }
    }

    return 0;
}
