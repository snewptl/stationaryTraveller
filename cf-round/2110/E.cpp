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
int n;
int count;
std::vector<std::set<int>> vec[2];
std::map<int, int> mp;
int ans[maxn];
int vis[maxn];
int a[2][maxn];
bool solve() {
    int sum[2] = {0, 0};
    pii start = {0, 1};
    for (int i = 0; i < 2; ++i) {
        for (int j = 1; j <= count; ++j) {
            sum[i] += vec[i][j].size() / 2;
            if (vec[i][j].size() % 2 == 1) start = {i, j};
        }
    } 
    if (sum[1] + sum[0] < n  - 1) return false;
    ans[1] = *vec[start.first][start.second].begin();
    vis[ans[1]] = 1;
    
    for (int i = 2; i <= n; ++i) {
        std::set<int>::iterator it;
        start.first ^= 1;
        while (true) {
            int idx = mp[a[start.first][ans[i - 1]]];
            it = vec[start.first][idx].begin();
            if (vec[start.first][idx].empty()) 
                return false;
            if (vis[*it]) vec[start.first][idx].erase(it);
            else break;
        }
        ans[i] = *it;
        vis[ans[i]] = 1;
    }

    std::cout << "YES\n";
    for (int i = 1; i <= n; ++i) std::cout << ans[i] << ' ';
    std::cout << '\n';
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
        std::cin >> n;
        for (int i = 0; i < 2; ++i) {
            vec[i].clear();
            vec[i].resize(n * 2 + 1);
        }
        mp.clear();
        count = 0;
        for (int i = 1; i <= n; ++i) {
            int v, p;
            std::cin >> v >> p;
            if (!mp.count(v)) mp[v] = ++count;
            vec[0][mp[v]].insert(i);
            if (!mp.count(p)) mp[p] = ++count;
            vec[1][mp[p]].insert(i);
            a[0][i] = v;
            a[1][i] = p;
            vis[i] = 0;
        }
        if(!solve()) std::cout << "NO\n";
    }

    return 0;
}
