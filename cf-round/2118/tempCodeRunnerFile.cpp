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
int n;
ll k;
ll p[maxn];
ll d[maxn];
int q;
ll a[maxn];
ll to[maxn << 1];
bool in_stack[maxn << 1], is_circle[maxn << 1], vis[maxn << 1];
std::map<ll, int> mp;
int count;
std::vector<std::vector<pli>> pos[2]; 
int hash(ll x) {
    x = (x % k + k) % k;
    if (mp.count(x)) return mp[x];
    else return mp[x] = ++count;
}
int try_hash(ll x) {
    x = (x % k + k) % k;
    if (mp.count(x)) return mp[x];
    else return 0;
}
void clear() {
    count = 0;
    mp.clear();
    for (int i = 0; i < 2 * n; ++i) {
        is_circle[i] = 0;
        in_stack[i] = 0;
        vis[i] = 0;
        to[i] = -1;
    }
    for (int i = 0; i < 2; ++i) {
        pos[i].clear();
        pos[i].resize(n * 2 + 1);
    }

}
void dfs(int i) {
    in_stack[i] = 1;
    vis[i] = 1;
    if (to[i] != -1) {
        int v = to[i];
        if (in_stack[v]) is_circle[i] = 1;
        else {
            if (!vis[v]) dfs(v);
            is_circle[i] = is_circle[v];
        }  
    } else {
        is_circle[i] = 0;
    }
    in_stack[i] = 0;
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
        std::cin >> n >> k;
        for (int i = 0; i < n; ++i) std::cin >> p[i];
        for (int i = 0; i < n; ++i) std::cin >> d[i];
        clear();

        for (int i = 0; i < n; ++i) {
            pos[1][hash(d[i] - p[i])].push_back({p[i], i});
            pos[0][hash(d[i] + p[i])].push_back({p[i], i});
        }

        for (int i = 0; i < n; ++i) {
            int cur = try_hash(-p[i] + d[i]);
            if (cur && !pos[1][cur].empty()) {
                int u = i * 2;
                auto it = std::upper_bound(all(pos[1][cur]), std::make_pair(p[i], i));
                if (it != pos[1][cur].end()) {
                    to[u] =  it->second * 2 + 1;
                }
            }
            cur = try_hash(p[i] + d[i]);
            if (cur && !pos[0][cur].empty()) {
                int u = i * 2 + 1;
                auto it = std::lower_bound(all(pos[0][cur]), std::make_pair(p[i], i));
                if (it != pos[0][cur].begin()) {
                    --it;
                    to[u] = it->second * 2;
                }
            }
        } 

        for (int i = 0; i < n * 2; ++i) {
            if (vis[i]) continue;
            dfs(i);
        }

        std::cin >> q;
        for (int i = 1; i <= q; ++i) {
            std::cin >> a[i];
            int cur = try_hash(-a[i]);
            int flag;
            if (!cur || pos[cur].empty()) {
                flag = 1;
            } else {
                auto it = std::lower_bound(all(pos[1][cur]), std::make_pair(a[i], 0));
                int u = it->second * 2 + 1;
                flag = !is_circle[u];
            }
            std::cout << (flag ? "YES\n" : "NO\n");
        }
    }

    return 0;
}
