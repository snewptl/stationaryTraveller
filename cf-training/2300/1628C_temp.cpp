#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <assert.h>
#include <memory.h>
#include <array>
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
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
const int n = 6;
bool is_out(int x) {
    if (x < 0 || x >= n) return true;
    return false;
}
pii next(int row, int col) {
    if (col == n - 1) {
        col = 0;
        row += 1;
    } else {
        col += 1;
    }
    return {row, col};
}
void dfs(int row, int col, std::array<std::array<int, n>, n> arr, std::array<std::array<int, n>, n> opt) {
    if (row == n) {
        int flag = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                flag &= arr[i][j];
            }
        }
        if (flag) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    std::cout << opt[i][j] << ' ';
                }
                std::cout << '\n';
            }
            std::cout << '\n';
            exit(0);
        }
        return;
    }
    auto [to_row, to_col] = next(row, col);
    dfs(to_row, to_col, arr, opt);
    opt[row][col] = 1;
    for (int t = 0; t < 4; ++t) {
        int nrow = dx[t] + row;
        int ncol = dy[t] + col;
        if (is_out(nrow) || is_out(ncol)) continue;
        arr[nrow][ncol] ^= 1;
    }
    dfs(to_row, to_col, arr, opt);
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    std::cin >> T;
    while (T--) {
        std::array<std::array<int, n>, n> arr, opt;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                arr[i][j] = 0;
                opt[i][j] = 0;
            }
        }
        dfs(0, 0, arr, opt);
    }

    return 0;
}
// 10 : 51 - 