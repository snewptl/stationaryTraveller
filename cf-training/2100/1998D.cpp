#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;
typedef double db;
typedef long double ldb;
const int maxn = 2e5 + 5;
int n, m;
std::vector<int> e[maxn];
int farest[maxn], dis[maxn];
std::string s;
int maxstep;
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
        for (int i = 1; i <= n; ++i) {
            farest[i] = i + 1;
            dis[i] = i - 1;
        }
        for (int i = 1; i <= m; ++i) {
            int u, v; std::cin >> u >> v;
            e[v].push_back(u);
            farest[u] = std::max(farest[u], v);
        }
        s = "1";
        for (int i = 1; i < n - 1; ++i) {
            for (auto v : e[i]) {
                dis[i] = std::min(dis[i], dis[v] + 1);
                
            }
            if (i) dis[i] = std::min(dis[i], dis[i - 1] + 1);
            maxstep = std::max(maxstep, (farest[i] - 1 - dis[i] - 1));
            if (i < maxstep) s += '0';
            else s += '1';
        }
        std::cout << s << '\n'; 

        maxstep = 0;
        for (int i = 1; i <= n; ++i) {
            e[i].clear();
        }
    }

    return 0;
}
