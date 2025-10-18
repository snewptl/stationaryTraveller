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
const int maxn = 5e5 + 5;
const ll mod = 998244353;
struct node {
    int l, r;
    int row, id, type;
    bool operator<(const node &x) {
        return row == x.row ? l < x.l : row < x.row;
    }
    node(int l, int r, int row, int id, int type) {
        this->l = l;
        this->r = r;
        this->row = row;
        this->id = id;
        this->type = type;
    }
};
int n, q;
std::pair<pii, pii> reg[maxn];
std::vector<node> all_seg;
int fa[maxn][21];
int dep[maxn];
std::vector<std::vector<int>> e;
int dfn[maxn], dfn_num;
int fw[maxn];
void dfs(int u) {
    dfn[u] = dfn_num++;
    for (auto v : e[u]) {
        dfs(v);
    }
}
void init() {
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= 20; ++j) {
            fa[i][j] = -1;
        }
        dep[i] = 0;
    }
    e.clear();
    e.resize(n + 1);
    std::set<pii> s;
    s.insert({0, 0});
    for (node it : all_seg) {
        if (it.type == 1) {
            s.erase({it.l, it.id});
            s.erase({it.r, fa[it.id][0]});
        } else {
            auto ptr = s.lower_bound({it.l, 0});
            assert(ptr != s.begin());
            --ptr;
            fa[it.id][0] = ptr->second;
            dep[it.id] = dep[ptr->second] + 1;
            s.insert({it.l, it.id});
            s.insert({it.r, fa[it.id][0]});
            e[fa[it.id][0]].push_back(it.id);
        }
    }
    for (int j = 1; j <= 20; ++j) {
        for (int i = 1; i <= n; ++i) {
            if (fa[i][j - 1] != -1) {
                fa[i][j] = fa[fa[i][j - 1]][j - 1];
            }
        }
    }
    dfn_num = 0;
    dfs(0);
    for (int i = 1; i <= n; ++i) {
        fw[i] = 0;
    }
}
int lca(int x, int y) {
    if (dep[x] < dep[y]) std::swap(x, y);
    for (int i = 20; i >= 0; --i) {
        if (fa[x][i] == -1) continue;
        if (dep[fa[x][i]] < dep[y]) continue;
        x = fa[x][i];
    }
    for (int i = 20; i >= 0; --i) {
        if (fa[x][i] == -1) continue;
        if (fa[x][i] == fa[y][i]) continue;
        x = fa[x][i], y = fa[y][i];
    }
    return x == y ? x : fa[x][0];
} 
int lowbit(int x) {
    return x & (-x);
}
void update(int x, int delta) {
    for (int i = x; i <= n; i += lowbit(i)) {
        fw[i] += delta;
    }
}
int query(int x) {
    int res = 0;
    for (int i = x; i; i -= lowbit(i)) {
        res += fw[i];
    }
    return res;
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> q;
    all_seg.clear();
    for (int i = 1; i <= n; ++i) {
        std::cin >> reg[i].first.first >> reg[i].first.second >> reg[i].second.first >> reg[i].second.second;
        pii cur = {reg[i].first.first, reg[i].second.first};
        all_seg.push_back(node(reg[i].first.first, reg[i].second.first, reg[i].first.second, i, 0));
        all_seg.push_back(node(reg[i].first.first, reg[i].second.first, reg[i].second.second, i, 1));
    }
    std::sort(all(all_seg));
    init();
    std::set<pii> s;
    while (q--) {
        std::string str;
        int x;
        std::cin >> str >> x;
        if (str[0] == '^') {
            int delta = s.count({dfn[x], x}) ? -1 : 1;
            s.insert({dfn[x], x});
            auto pre = s.lower_bound({dfn[x], x});
            auto nxt = pre;
            int rt = 0;
            if (pre != s.begin()) {
                --pre;
                int top = lca(pre->second, x);
                if (dep[top] > dep[rt]) rt = top;
            }
            ++nxt;
            if (nxt != s.end()) {
                int top = lca(nxt->second, x);
                if (dep[top] > dep[rt]) rt = top;
            }
            pii cur = {dep[rt] + 1, dep[x]};
            update(cur.first, delta);
            if (cur.second < n) update(cur.second + 1, -delta);
            if (delta < 0) s.erase({dfn[x], x});
        } else {
            std::cout << query(x + 1) << '\n';
        }
    }

    return 0;
}
