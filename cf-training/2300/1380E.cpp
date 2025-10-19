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
std::vector<int> loc;
std::vector<std::set<int>> s;
int dsu[maxn];
pii seg[maxn];
int find(int x) {
    return dsu[x] == x ? x : dsu[x] = find(dsu[x]);
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> m;
    loc.clear();
    loc.resize(m + 1);
    s.clear();
    s.resize(m + 1);
    for (int i = 1; i <= m; ++i) {
        loc[i] = i;
    }
    for (int i = 1; i <= n; ++i) {
        seg[i] = {i, i};
        dsu[i] = i;
    }
    int ans = n - 1;
    for (int i = 1; i <= n; ++i) {
        int t; std::cin >> t;
        s[t].insert(i);
        if (i != 1) {
            int pre = i - 1;
            if (s[t].count(pre)) {
                --ans;
                s[t].erase(pre);
                seg[i] = {seg[pre].first, i};
                dsu[pre] = i;
            }
        }
    }
    std::cout << ans << '\n';
    for (int i = 1; i < m; ++i) {
        int a, b;
        std::cin >> a >> b;
        if (s[loc[a]].size() < s[loc[b]].size()) std::swap(loc[a], loc[b]);
        for (auto it : s[loc[b]]) {
            s[loc[a]].insert(it);
            if (it != 1) {
                int pre = seg[it].first - 1;
                if (s[loc[a]].count(pre)) {
                    --ans;
                    s[loc[a]].erase(pre);
                    seg[it] =  {seg[pre].first, it};
                    dsu[pre] = it;
                }
            }
            if (it != n) {
                int nxt = seg[find(it + 1)].second;
                if (s[loc[a]].count(nxt)) {
                    --ans;
                    s[loc[a]].erase(it);
                    seg[nxt] = {seg[it].first, nxt};
                    dsu[it] = nxt;
                }
            }
        }
        std::cout << ans << '\n';
    }
    return 0;
}
