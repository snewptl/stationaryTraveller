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
const int maxn = 4e5 + 5;
int n, m;
std::vector<int> a[maxn];
std::vector<int> e[maxn];
std::map<int, int> mp;
int rk;
int vis[maxn], val[maxn];
int dis[maxn];
int default_dis = 0;
void dfs(int u) {
    vis[u] = 1;
    if (e[u].size() == 0) {
        dis[u] = val[u];
    }
    else if (e[u].size() == 1) {
        int v = e[u][0];
        default_dis = std::max(default_dis, val[u]);
        if (!vis[v]) dfs(v);
        dis[u] = dis[v];
        
    }
    else {
        int final = 0;
        for (auto v : e[u]) {
            if (!vis[v]) dfs(v);
            final = std::max(final, dis[v]);
        } 
        default_dis = std::max(default_dis, final);
        dis[u] = final;
    }
       
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
        for (int i = 1; i <= n; ++i) {
            int len; std::cin >> len;
            for (int j = 1; j <= len; ++j) {
                int x; std::cin >> x;
                a[i].push_back(x);
            }
            sort(all(a[i]));
            int cur = 0, idx = 0, cnt = 0;
            int temp[2];
            while(cnt < 2) {
                if (idx == len) {
                    temp[cnt] = cur;
                    ++cur, ++cnt;
                    continue;
                }
                while (idx < len) {
                    if (cur == a[i][idx]) ++cur, ++idx;
                    else if (cur == a[i][idx] + 1) ++idx; 
                    else {
                        temp[cnt] = cur;
                        ++cnt, ++cur;
                        break;
                    }
                } 
            } 
            if (!mp.count(temp[0])) mp[temp[0]] = ++rk, val[rk] = temp[0];
            if (!mp.count(temp[1])) mp[temp[1]] = ++rk, val[rk] = temp[1];
            e[mp[temp[0]]].push_back(mp[temp[1]]);
        }

        for (int i = 1; i <= rk; ++i) {
            if (!vis[i]) dfs(i);
        }
        ll ans = 0;
        if (default_dis < m) {
            ans = 1LL * (default_dis  + m) * (m - default_dis + 1) / 2 + 1ll * default_dis * default_dis;
        } else {
            ans = 1ll * default_dis * (m + 1);
        }
        
        for (int i = 1; i <= rk; ++i) {
            if (e[i].size() && m >= val[i]) ans += std::max(dis[i], default_dis) - default_dis;
        }
        std::cout << ans << '\n';

        for (int i = 1; i <= n; ++i) {
            a[i].clear();
        } 
        mp.clear();
        default_dis = 0;
        for (int i = 1; i <= rk; ++i) {
            e[i].clear();
            vis[i] = 0;
            dis[i] = 0;
            val[i] = 0;
        }
        rk = 0;
    }

    return 0;
}
