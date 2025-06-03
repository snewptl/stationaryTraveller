#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;
typedef double db;
typedef long double ldb;
const int maxn = 2e5 + 5;
int n, m, a[maxn];
std::map<int, int>mp;
ll lower[maxn], upper[maxn];
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
        for (int i = 1; i <= m; ++i) {
            std::cin >> a[i];
        }
        std::sort(a + 1, a + m + 1);
        for (int i = 1; i <= m; ++i) {
            lower[i] = a[i] / 100 + lower[i - 1];
            upper[i] = a[m - i + 1] / 100 + upper[i - 1];
        }
        int ans = 0, idx = 0;
        for (int i = 0; i <= n / 2; ++i) {
            if (upper[i] - lower[i] + upper[m - i] - lower[m - i] > ans) {
                ans = upper[i] - lower[i] + upper[m - i] - lower[m - i];
                idx = i;
            }
        }
        for (int i = 1; i <= idx; ++i) {
            for (int j = 1; j <= 3; ++j)
                std::cout << a[i] << ' ' << a[m - idx + i] << ' '; 
            std::cout << '\n';
        }
        for (int i = 1; i <= n - idx; ++i) {
            for (int j = 1; j <= 3; ++j)
                std::cout << a[m - i + 1] << ' ' << a[n - idx - i + 1] << ' '; 
            std::cout << '\n';
        }       
    }

    return 0;
}
