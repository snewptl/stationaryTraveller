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
const int maxn = 5e5 + 5;
const ll mod = 998244353;
int n;
int a[maxn], b[maxn];
int pos[maxn];
int end[maxn];
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
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
        }
        for (int i = 1; i <= n; ++i) {
            std::cin >> b[i];
        }
        ll ans = 0;
        for (int i = 1; i <= n; ++i) {
            pos[i] = n + 1;
            end[i] = n + 1;
        }
        end[n + 1] = n + 1;
        for (int i = n; i >= 1; --i) {
            pos[a[i]] = i;
            pos[b[i]] = i; 
            if (a[i] != b[i]) {
                end[i] = i;
            } else {
                if (a[i] == n) end[i] = n + 1;
                else end[i] = end[pos[a[i] + 1]];
            }
            ans += end[pos[1]] - i;
        }
        std::cout << ans << '\n';
    }

    return 0;
}
