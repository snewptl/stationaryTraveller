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
const int maxn = 1e6 + 5;
const ll mod = 998244353;
int n;
ll m;
int vis[maxn];
bool solve() {
    std::vector<int> vec;
    for (int i = 1; i <= n; ++i) {
        vis[i] = 0;
    }
    if (m < 0) return 0;
    for (int i = 1; i <= n; ++i) {
        if (n - i <= m) {
            vec.push_back(n - i + 1);
            vis[n - i + 1] = 1;
            m -= n - i;
        } else {
            vec.push_back(m + 1);
            vis[m + 1] = 1;
            m = 0;
            break;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) vec.push_back(i);
    }
    if (m != 0) return false;
    std::cout << vec[0] << '\n';
    for (int i = 0; i < vec.size() - 1; ++i) {
        std::cout << vec[i] << ' ' << vec[i + 1] << '\n';
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
        std::cin >> n >> m;
        m -= n;
        if(!solve()) std::cout << "-1\n";
    }

    return 0;
}
