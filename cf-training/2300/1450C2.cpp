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
int n;
int mp[305][305];
std::set<std::pair<pii, pii>, std::greater<std::pair<pii, pii>>> s;
pii count(int x, int y) {
    int col = 0, row = 0;
    for (int i = std::max(1, x - 2); i <= std::min(n - 2, x); ++i) {
        int flag = 1;
        for (int j = 0; j < 3; ++j) {
            if (mp[i + j][y] != mp[x][y]) flag = 0;
        }
        row += flag;
    }
    for (int i = std::max(1, y - 2); i <= std::min(n - 2, y); ++i) {
        int flag = 1;
        for (int j = 0; j < 3; ++j) {
            if (mp[x][i + j] != mp[x][y]) flag = 0;
        }
        col += flag;
    }
    return {row + col, std::min(row, col)};
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
        std::cin >> n;
        s.clear();
        for (int i = 1; i <= n; ++i) {
            std::string str;
            std::cin >> str;
            for (int j = 0; j < str.size(); ++j) {
                if (str[j] == '.') {
                    mp[i][j + 1] = 0;
                } else if (str[j] == 'O') {
                    mp[i][j + 1] = 1;
                } else {
                    mp[i][j + 1] = 2;
                }
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (mp[i][]) s.insert({count(i, j), {i, j}});
            }
        }
    }

    return 0;
}
// 20 : 37 - 