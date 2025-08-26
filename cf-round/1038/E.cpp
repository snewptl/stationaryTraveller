#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <bitset>
#include <memory.h>
#include <assert.h>
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;
typedef double db;
typedef long double ldb;
const int maxn = 2e5 + 5;
const ll mod = 998244353;
int ans = 0;
int n;
std::vector<int> a[5][5], sum[5][5];
int cur[5][5];

void dfs(std::vector<int> used, int l, int r, int add) {
    ans = std::max(ans, add);
    for (int i = 1; i <= 3; ++i) {
        for (int j = i + 1; j <= 4; ++j) {
            if (cur[i][j] == a[i][j].size()) continue;
            bool can = 0;
            int nl, nr;
            if (r == 0) {
                can = 1;
                nl = i;
                nr = j;
            } else if (l == i) {
                can = 1;
                nl = j;
                nr = r;
            } else if (l == j) {
                can = 1;
                nl = i;
                nr = r;
            } else if (r == i) {
                can = 1;
                nl = j;
                nr = l;
            } else if (r == j) {
                can = 1;
                nl = l;
                nr = i;
            }
            if (can) {
                if (nl > nr) std::swap(nl, nr);
                std::vector<int> update;
                if (!used[i]) update.push_back(i);
                if (!used[j]) update.push_back(j);
                for (auto it : update) {
                    used[it] = 1;
                    if (!sum[it][it].empty()) add += sum[it][it].back();
                }
                
                add += a[i][j][cur[i][j]];
                cur[i][j] += 1;
                dfs(used, nl, nr, add); 
                for (auto it : update) {
                    used[it] = 0;
                    if (!sum[it][it].empty()) add -= sum[it][it].back();
                }
                --cur[i][j];
                add -= a[i][j][cur[i][j]];
            }
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
        int l, val, r;
        std::cin >> l >> val >> r;
        if (l > r) std::swap(l, r);
        a[l][r].push_back(val);
    }
    for (int i = 1; i <= 4; ++i) {
        for (int j = i; j <= 4; ++j) {
            std::sort(all(a[i][j]));
            std::reverse(all(a[i][j]));
            sum[i][j] = a[i][j];
            for (int t = 1; t < a[i][j].size(); ++t) {
                sum[i][j][t] += sum[i][j][t - 1];
            }
        }
    }
    for (int i = 1; i <= 4; ++i) {
        if (!sum[i][i].empty()) ans = std::max(ans, sum[i][i].back());
    }
    
    std::vector<int> used;
    used.resize(5, 0);
    dfs(used, 0, 0, 0);
    std::cout << ans << '\n';

    return 0;
}
