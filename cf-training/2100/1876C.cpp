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
int n, a[maxn];
std::vector<int> e[maxn];
std::vector<pii> rk;
int vis[maxn];
void clean() {
    for (int i = 1; i <= n; ++i) {
        e[i].clear();
        vis[i] = 0;
    }
    rk.clear();
}
bool solve() {
    for (auto [sz, idx] : rk) {
        if (sz == 1) {
            if (e[idx][0] == idx) return false;
            while(e[a[e[idx][0]]].size() == 1)
        }
    }
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
        e[a[i]].push_back(i);
    }

    for (int i = 1; i <= n; ++i) {
        if (e[i].empty()) continue;
        rk.push_back({e[i].size(), i});
    }  
    sort(all(rk));

    if (!solve()) std::cout << "-1\n";
    else {

    }

    clean();





    return 0;
}
