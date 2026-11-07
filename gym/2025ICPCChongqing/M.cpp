#include <bits/stdc++.h>
const int maxn = 2e5 + 5;
const int maxm = 1e6 + 5;
int n;
int c[maxn];
int dep[maxn], fa[maxn][20], dfn[maxn], dfn_num;
int end_dfn[maxn];
std::vector<std::vector<int>> e;
std::vector<int> seg[maxm];
std::map<int, int> fac[maxn];
struct Tree {
    std::map<int, int> mp;
    std::vector<int> vec;
    std::vector<int> mx;
    int n;
    Tree()=default;
    void init(std::vector<int> &s) {
        mp.clear();
        mx.clear();
        for (auto u : s) {
            vec.push_back(dfn[u]);
            if (end_dfn[u] != dfn[u]) vec.push_back(end_dfn[u]);
        }
        std::sort(vec.begin(), vec.end());
        vec.resize(std::unique(vec.begin(), vec.end()) - vec.begin());
        for (int i = 0; i < (int)vec.size(); ++i) {
            mp[vec[i]] = i * 2 + 1;
        }            
        n = (int)vec.size() * 2 + 1;
        mx.resize(vec.size() * 4 + 4, 0);
    }
    void update(int rt, int l, int r, int xl, int xr, int id) {
        if (l == xl && r == xr) {
            mx[rt] = id;
            return;
        }
        int mid = (l + r) / 2;
        if (xl <= mid) update(rt << 1, l, mid, xl, std::min(xr, mid), id);
        if (xr > mid) update(rt << 1 | 1, mid + 1, r, std::max(mid + 1, xl), xr, id);
    }
    int query(int rt, int l, int r, int pos) {
        if (l == r) {
            return mx[rt];
        }
        int mid = (l + r) / 2;
        if (pos <= mid) return query(rt << 1, l, mid, pos);
        else return query(rt << 1 | 1, mid + 1, r, pos);
    }
    int query(int u) {
        int pos = 0;
        if (mp.count(dfn[u])) {
            pos = mp[dfn[u]];
        } else {
            auto it = std::upper_bound(vec.begin(), vec.end(), dfn[u]) - vec.begin();
            pos = it * 2;
        }
        return query(1, 0, n - 1, pos);
    }
    void update(int u) {
        update(1, 0, n - 1, mp[dfn[u]], mp[end_dfn[u]], u);
    }
}t[maxm];
struct Que {
    int u, v;
}que[maxn];
int lca(int u, int v) {
    if (dep[u] < dep[v]) std::swap(u, v);
    for (int i = 19; i >= 0; --i) {
        if (fa[u][i] && dep[fa[u][i]] >= dep[v]) {
            u = fa[u][i];
        }
    }
    for (int i = 19; i >= 0; --i) {
        if (fa[u][i] && fa[v][i] && dep[fa[u][i]] != dep[fa[v][i]]) {
            u = fa[u][i];
            v = fa[v][i];
        }
    }
    if (u != v) u = fa[u][0];
    return u;
}
void dfs(int u, int p) {
    dep[u] = dep[p] + 1;
    dfn[u] = ++dfn_num;
    fa[u][0] = p;
    for (auto v : e[u]) {
        if (v == p) continue;
        dfs(v, u);
    }
    end_dfn[u] = dfn_num;
}
void clear() {
    dfn_num = 0;
    e.clear();
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 20; ++j) {
            fa[i][j] = 0;
        }
        dep[i] = 0;
        dfn[i] = 0;
        fac[i].clear();
        seg[i].clear();
    }
}
int main(){
// #ifdef LOCAL
    freopen("m.in","r",stdin);
// #endif
    int T = 1;
    // std::cin >> T;
    while(T--) {
        std::cin >> n >> c[1];
        e.resize(n + 1);
        for (int i = 2; i <= n; ++i) {
            std::cin >> c[i];
            int u, v;
            std::cin >> u >> v;
            e[v].push_back(i);
            e[i].push_back(v);
            que[i].u = u;
            que[i].v = v;
        }   
        dfs(1, 0);
        for (int i = 1; i <= n; ++i) {
            int cur = c[i];
            int count = 0;
            for (int j = 2; j * j <= cur; j += 1) {
                if (cur % j == 0) {
                    while (cur % j == 0) {
                        cur /= j;
                        count += 1;
                    }
                    fac[i][j] = count;
                }
            }
            for (auto [p, q] : fac[i]) {
                seg[p].push_back(i);
            } 
        }
        for (int i = 2; i <= 1e6; ++i) {
            if (seg[i].empty()) continue;
            t[i].init(seg[i]);
        }
        auto link_count = [](int p, int &q, int u, int top) {
            int pre = t[p].query(u);
            if (fac[u].count(p)) q -= std::min(q, fac[u][p]);
            while (q > 0 && pre && dep[pre] >= dep[top]) {
                u = pre;
                pre = t[p].query(u);
                q -= std::min(q, fac[u][p]);
            }
        };
        for (int i = 1; i <= n; ++i) {
            if (i == 1) {
                for (auto [p, q] : fac[i]) {
                    t[p].update(1);
                }
                std::cout << c[1] << ' ';
                continue;
            }
            int top = lca(que[i].u, que[i].v);
            auto new_v = que[i].v;
            for (int j = 19; j >= 0; --j) {
                if (fa[new_v][j] && dep[fa[new_v][j]] > dep[top]) {
                    new_v = fa[new_v][j];
                }
            }
            c[i] = 1;
            for (auto [p, q] : fac[i]) {
                link_count(p, q, que[i].u, top);
                if (top != que[i].v) link_count(p, q, que[i].v, new_v);
                if (q > 0) {
                    t[p].update(i);
                    for (int j = 1; j <= q; ++j) c[i] *= p;
                }
                fac[i][p] = q; 
            }

            std::cout << c[i] << ' ';   
        }
        std::cout << '\n';
        clear();
    }
    return 0;
}