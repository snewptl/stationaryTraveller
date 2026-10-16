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
const int maxn = 2e6 + 5;
const ll mod = 998244353;
int n;
std::vector<std::vector<int>> node;
ll fw[3][maxn];
int count[3][maxn];
int le[2][maxn], ri[2][maxn];
int lowbit(int x) {
    return x &(-x);
}
int query(int type, int x) {
    int res = 0;
    while (x) {
        res += fw[type][x];
        x -= lowbit(x);
    }
    return res;
}
int query(int type, int l, int r) {
    return query(type, r) - query(type, l - 1);
}
void update(int type, int x, int delta) {
    int pre = count[type][x];
    count[type][x] += delta; 
    if (count[type][x] == 0 && pre == 1) {
        if (type == 2) {
            while (x <= n) {
                fw[type][x] -= 1;
                x += lowbit(x);
            }
            
        } 
    } else if (count[type][x] == 1 && pre == 0) {
        if (type == 2) {
            while (x <= n) {
                fw[type][x] += 1;
                x += lowbit(x);
            }
        } 
    }
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("0_input.txt", "r", stdin);
    // freopen("0_output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> n;
        node.clear();
        node.resize(n + 1);
        for (int i = 0; i < 3; ++i) {
            for (int j = 1; j <= n; ++j) {
                fw[i][j] = 0;
                count[i][j] = 0;
            }
        }
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j <= n + 1; ++j) {
                le[i][j] = n + 1;
                ri[i][j] = 0;
            }
        }
        for (int i = 1; i <= n; ++i) {
            int x, y;
            std::cin >> x >> y;
            node[x].push_back(y);
        }
        ll ans = 0;
        for (int i = 1; i <= n; ++i) {
            for (auto j : node[i]) {
                update(2, j, 1);
            }
        }
        for (int i = 1; i <= n; ++i) {
            le[0][i] = std::min(le[0][i - 1], le[0][i]);
            ri[0][i] = std::max(ri[0][i - 1], ri[0][i]);
            for (auto j : node[i]) {
                le[0][i] = std::min(j, le[0][i]);
                ri[0][i] = std::max(j, ri[0][i]);
            }
        }
        for (int i = n; i >= 1; --i) {
            le[1][i] = std::min(le[1][i + 1], le[1][i]);
            ri[1][i] = std::max(ri[1][i + 1], ri[1][i]);
            for (auto j : node[i]) {
                le[1][i] = std::min(j, le[1][i]);
                ri[1][i] = std::max(j, ri[1][i]);
            }
        }
        for (int i = 1; i <= n; ++i) {
            if (node[i].empty()) continue;
            int l = std::max(le[0][i], le[1][i + 1]), r = std::min(ri[0][i], ri[1][i + 1]);
            int res = query(2, l, r);
            res -= 1;
            if (res > 0) ans += res;
            
        }
        std::cout << ans << '\n';
    }


    return 0;
}
