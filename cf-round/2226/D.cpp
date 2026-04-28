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
int a[maxn];
int min[2][maxn];
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
        int mx[2] = {0, 0};
        int mn[2] = {(int)1e9, (int)1e9};
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
            mx[a[i] % 2] = std::max(mx[a[i] % 2], a[i]);
            mn[a[i] % 2] = std::min(mn[a[i] % 2], a[i]);
        }
        min[0][n + 1] = 1e9;
        min[1][n + 1] = 1e9; 
        int ans = 1;
        for (int i = n; i >= 1; --i) {
            int cur = a[i] % 2;
            int inv = cur ^ 1;
            if (min[a[i] % 2][i + 1] < a[i]) {
                int flag = 0;
                if (mx[inv] > a[i] || mn[inv] < min[cur][i + 1]) flag = 1; 
                ans &= flag; 
            }
            min[0][i] = min[0][i + 1];
            min[1][i] = min[1][i + 1];
            min[a[i] % 2][i] = std::min(min[a[i] % 2][i], a[i]);
        }
        if (ans) std::cout << "YES\n";
        else std::cout << "NO\n";
    }

    return 0;
}
