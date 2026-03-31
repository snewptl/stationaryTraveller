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
<<<<<<< HEAD

=======
int n;
int p[maxn];
int ans[maxn];
>>>>>>> 33881cd33f7faea7c29e55e4b113180466582591
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
<<<<<<< HEAD
=======
        std::cin >> n;
        for (int i = 1; i <= n; ++i) {
            ans[i] = 0;
        }
        for (int i = 1; i <= n; ++i) {
            std::cin >> p[i];
        }
        for (int i = 1; i <= n; ++i) {
            if (p[i] <= i) ans[i] += 1;
            else {
                ans[i] += 1;
                ans[p[i]] -= 1; 
            }
        }
        int fin = 0;
        for (int i = 1; i <= n; ++i) {
            ans[i] += ans[i - 1];
            fin = std::max(fin, ans[i]);
        }
        std::cout << fin << '\n';
        
>>>>>>> 33881cd33f7faea7c29e55e4b113180466582591
    }

    return 0;
}
