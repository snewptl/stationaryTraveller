namespace tarjan {
    int dfn[maxn], low[maxn], dfncnt, s[maxn], in_stack[maxn], tp;
    int scc[maxn], sc; 
    int sz[maxn]; 

    void tarjan(int u) {
        low[u] = dfn[u] = ++dfncnt, s[++tp] = u, in_stack[u] = 1;
        for (auto v : e[u]) {
            if (!dfn[v]) {
                tarjan(v);
                low[u] = std::min(low[u], low[v]);
            } else if (in_stack[v]) {
                low[u] = std::min(low[u], dfn[v]);
            }
        }
        if (dfn[u] == low[u]) {
            ++sc;
            do {
                scc[s[tp]] = sc;
                sz[sc]++;
                in_stack[s[tp]] = 0;
            } while (s[tp--] != u);
        }
    }

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
            do {
                scc[s[tp]] = sc;
                sz[sc]++;
                in_stack[s[tp]] = 0;
            } while (s[tp--] != u);
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