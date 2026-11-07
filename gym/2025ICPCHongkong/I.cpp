#include<bits/stdc++.h>
using ll = long long;
const ll mod = 1e9 + 7;
int n, m;
int p[505][505];
int inv[505][505];
ll ans;
ll dfs(std::vector<std::pair<ll, int>>& links, int u, int len) {
    if (len == 1) return 1;
    std::vector<int> vis(n + 1, 0);
    for (int i = 1; i <= m; ++i) {
        int nxt_pos = inv[i][u] + 1;
        int candi_u = p[i][nxt_pos];
        vis[candi_u] = 1;
    }
    auto try_this = [](int u, int len){
        std::vector<int> booked(n + 1, 0);
        int count = 0;
        for (int i = 1; i <= m; ++i) {
            int ed = inv[i][u] + len - 1;
            if (ed > n) return false;
            for (int j = inv[i][u]; j <= ed; ++j) {
                if (!booked[p[i][j]]) {
                    booked[p[i][j]] = 1;
                    count += 1;
                }
            }
        }
        if (count != len) return false;
        return true;
    };
    auto last_seg = [](int u, int pre_len, int full_len) {
        std::vector<int> booked(n + 1, 0);
        int count = 0;
        for (int i = 1; i <= m; ++i) {
            int pos = inv[i][u] + pre_len;
            for (int j = pos; j <= inv[i][u] + full_len - 1; ++j) {
                if (!booked[p[i][j]]) {
                    booked[p[i][j]] = 1;
                    count += 1;
                }
            }
        }
        if (count != full_len - pre_len) return false;
        return true;
    };
    ll fac = 0;
    ll sum = 0;
    int flag = 0;
    std::vector<std::pair<ll, int>> new_links;
    for (auto [count, len] : links) {
        fac += count * len % mod;
        fac %= mod;
    }
    int pos = inv[1][u] + 1;
    while (pos <= inv[1][u] + len - 1) {
        int max_len = 1;
        for (int i = pos + 1; i <= inv[1][u] + len - 1; ++i) {
            if (vis[i]) break;
            if (try_this(p[1][pos], i - pos + 1)) {
                max_len = i - pos + 1;
            }
        }       

        if (max_len + pos - 1 == inv[1][u] + len - 1 && last_seg(u, pos - inv[1][u], len)) {
                std::vector<ll>suf(links.size());
                for (int i = links.size() - 1; i >= 0; --i) {
                    suf[i] = links[i].second;
                    if (i != links.size() - 1) suf[i] += suf[i + 1];
                    suf[i] %= mod;
                }
                for (int i = links.size() - 2; i >= 0; --i) {
                    links[i].second += links[i + 1].second
                }
                for (int i = 0; i < links.size(); ++i) {
                    new_links.push_back({links[i].first, (suf[i] - (i <= 1 ? 0 : suf[i - 2]) + mod) % mod});
                }
                new_links.push_back({links.back().first + 1, links.back().second});
        } else {
            if (!flag) {
                flag = 1;
                if (links.size() == 1 && links[0].second == 1) {
                    links[0] = {1, 2};
                } else {
                    std::vector<ll>suf(links.size());
                    for (int i = links.size() - 1; i >= 0; --i) {
                        suf[i] = links[i].second;
                        if (i != links.size() - 1) suf[i] += suf[i + 1];
                        suf[i] %= mod;
                    }
                    for (int i = links.size() - 2; i >= 0; --i) {
                        links[i].second += links[i + 1].second
                    }
                    for (int i = 0; i < links.size(); ++i) {
                        new_links.push_back({links[i].first, (suf[i] - (i <= 1 ? 0 : suf[i - 2]) + mod) % mod});
                    }
                    new_links.push_back({links.back().first + 1, links.back().second});
                }
            }
            sum += dfs(new_links, p[1][pos], max_len) * ;
            sum %= mod;
            
        }

        pos = pos + max_len;
        if (pos <= n) {
            vis[pos] = 1;
        }
    }
    

}
int main() {
    std::cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            std::cin >> p[i][j];
            inv[i][p[i][j]] = j; 
        }
    }
    std::vector<std::pair<ll, int>> start;
    start.push_back({1, 1});
    std::cout << dfs(start, 1, n) << '\n';
    return 0;
}