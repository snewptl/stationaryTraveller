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
const int maxn = 3e5 + 5;
const ll mod = 998244353;

int n, m, q;
std::vector<std::vector<int>> e;
std::vector<pii> seg;
int right[maxn];
ll prefix[maxn];
namespace tarjan {
    int dfn[maxn], low[maxn], dfncnt, s[maxn], in_stack[maxn], tp;
    int scc[maxn], sc; 
    int sz[maxn]; 

    void tarjan(int u, int p) { // bi - direct
        low[u] = dfn[u] = ++dfncnt, s[++tp] = u, in_stack[u] = 1;
        for (auto v : e[u]) {
            if (v == p) continue;
            if (!dfn[v]) {
                tarjan(v, u);
                low[u] = std::min(low[u], low[v]);
            } else if (in_stack[v]) {
                low[u] = std::min(low[u], dfn[v]);
            }
        }
        if (dfn[u] == low[u]) {
            ++sc;
            int min = n, max = 1; 
            do {
                scc[s[tp]] = sc;
                sz[sc]++;
                in_stack[s[tp]] = 0;
                max = std::max(max, s[tp]);
                min = std::min(min, s[tp]);
            } while (s[tp--] != u);
            if (min != max) seg.push_back({min, max});
        }
    }

    void clear() {
        for (int i = 1; i <= sc; ++i) {
            sz[i] = 0;
        }
        for (int i = 1; i <= n; ++i) {
            dfn[i] = low[i] = 0;
        }
        sc = 0;
        dfncnt = 0;
    }
};

int main() {
    #ifndef ONLINE_JUDGE
    freopen("0_input.txt", "r", stdin);
    // freopen("0_output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> m;
    e.clear();
    e.resize(n + 1);
    for (int i = 1; i <= m; ++i) {
        int u, v;
        std::cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) {
        if (!tarjan::scc[i]) tarjan::tarjan(i, 0);
    }
    std::set<int> s;
    for (auto [x, y] : seg) {
        s.insert(y);
    }
    for (int i = 1; i  <= n; ++i) right[i] = n;
    std::sort(all(seg));
    int last = 0, cur = *s.begin() - 1;
    for (auto [x, y] : seg) {
        for (int i = last + 1; i <= x; ++i) right[i] = cur;
        s.erase(y);
        last = x;
        if (!s.empty()) cur = *s.begin() - 1;
    }
    for (int i = 1; i <= n; ++i) {
        prefix[i] = right[i];
        if (i > 1) prefix[i] += prefix[i - 1];
    }
    std::cin >> q;
    while (q--) {
        int l, r;
        std::cin >> l >> r;
        auto pos = std::lower_bound(right + l, right + n + 1, r) - right;
        --pos;
        ll res = prefix[pos] - prefix[l - 1];
        res -= 1ll * (l - 1 + l - 1 + pos - l) * (pos - l + 1) / 2;
        res += 1ll * (r - pos) * (r - pos + 1) / 2;
        std::cout << res << '\n';
    }

    

    return 0;
}
