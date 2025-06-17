#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <assert.h>
#include <cmath>
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;
typedef double db;
typedef long double ldb;
const int maxn = 1e4 + 5;
const ll mod = 998244353;
int n, m;
int x[maxn];
int a[11][maxn];
int vis[11];
int count[maxn];
int ans, res[maxn], final[maxn];
int main() {
    #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    // std::cin >> T;
    while (T--) {
        std::cin >> n >> m;
        ans = -1;
        for (int i = 1; i <= n; ++i) std::cin >> x[i];
        for (int i = 1; i <= n; ++i) {
            std::string str;
            std::cin >> str;
            for (int j = 0; j < m; ++j) {
                a[i][j + 1] = str[j] - '0'; 
            }
        }
        {
            int res[1005];
            for (int i = 1; i <= m; ++i) {
                std::cin >> res[i];
            }
            int  temp = 0;
            for (int i = 1; i <= n; ++i) {
                int sum = 0;
                for (int j = 1; j <= m; ++j) {
                    if (a[i][j]) sum += res[j];
                }
                temp += std::abs(sum - x[i]);
                std::cout << "# " << i << " " << (sum > x[i]) << '\n';
            }
            std::cout << "$$$" << temp << '\n';
        }
        // for (int i = 1; i <= m; ++i) std::cout << final[i] << ' ';
        // std::cout << '\n';
    }

    return 0;
}

// 9 : 37

/*

4 4
6 2 0 10
1001 3 - 6
0010 4 - 2
0110 7 - 0
0101 5 - 10
1 3 4 2

4 4
6 2 0 10
1001 3 - 6
0010 4 - 2
0110 7 - 0
0101 4 - 10
2 3 4 1 
-1 0 2 0
*/