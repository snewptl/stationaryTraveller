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
int n, m;
std::vector<std::vector<int>> e;
int main() {
    #ifndef ONLINE_JUDGE
    freopen("0_input.txt", "r", stdin);
    // freopen("0_output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string s;
    std::cin >> s;
    if (s[0] == 'c') {
        int T = 1;
        std::cin >> T;
        while (T--) {
            std::cin >> n >> m;
            e.clear();
            e.resize(n + 1);
            for (int i = 1; i <= m; ++i) {
                int u, v;
                std::cin >> u >> v;
                e[u].push_back(v);
                e[v].push_back(u);
            }    
        }

    } else {

    }

    return 0;
}
