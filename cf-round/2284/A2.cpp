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
int vis[25];
int a[maxn];
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
        for (int i = 0; i <= 24; ++i) {
            vis[i] = 0;
        }
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i]; 
            vis[a[i]] += 1;
        }
        ll A = 0, B = 0;
        for (int i = 24; i >= 0; --i) {
            while (vis[i]) {
                vis[i] -= 1;
                if (A <= B) A += 1 << i; 
                else B += 1 << i;
            }   
        }
        std::cout << A * B << '\n';
    }

    return 0;
}
