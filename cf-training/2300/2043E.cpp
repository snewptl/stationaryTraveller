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
const int maxn = 1e3 + 5;
const ll mod = 998244353;
int n, m;
int A[maxn][maxn], B[maxn][maxn];
int a[31][maxn][maxn], b[31][maxn][maxn];
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
        std::cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                std::cin >> A[i][j];
                for (int k = 0; k < 30; ++k) {
                    if ((1 << k) & A[i][j]) a[k][i][j] = 1;
                    else a[k][i][j] = 0;
                }
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                std::cin >> B[i][j];
                for (int k = 0; k < 30; ++k) {
                    if ((1 << k) & B[i][j]) b[k][i][j] = 1;
                    else b[k][i][j] = 0;
                }
            }
        }       
        int solvable = 1;
        for (int k = 0; k < 30; ++k) {
            std::vector<pii> row_list;
            for (int row = 1; row <= n; ++row) {
                int count = 0;
                for (int col = 1; col <= m; ++col) {
                    count += b[k][row][col];
                }
                row_list.push_back({count, row});
            }
            std::sort(all(row_list));
            std::reverse(all(row_list));
            int can_use[maxn];
            for (int col = 1; col <= m; ++col) can_use[col] = 1;
            for (auto [_, row] : row_list) {
                int flag = 1;
                for (int col = 1; col <= m; ++col) {
                    if (a[k][row][col] && !b[k][row][col]) flag = 0;
                }
                if (!flag) {
                    for (int col = 1; col <= m; ++col) {
                        a[k][row][col] = 0;
                    }
                }
                for (int col = 1; col <= m; ++col) {
                    if (a[k][row][col] != b[k][row][col]) {
                        assert(a[k][row][col] == 0);
                        if (!can_use[col]) solvable = 0;
                        for (int new_row = 1; new_row <= n; ++new_row) {
                            a[k][new_row][col] = 1;
                        }
                    }
                }
                for (int col = 1; col <= m; ++col) {
                    can_use[col] = b[k][row][col];
                }
            }
        }
        if (solvable) std::cout << "YES\n";
        else std::cout << "NO\n";
    }

    return 0;
}
// 10 : 32 - 