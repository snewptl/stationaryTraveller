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
ll ans;
int n, s;
int a[maxn], b[maxn];
int pos_a[maxn], pos_b[maxn], vis[maxn];
std::set<int> st;
int count = 0;
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
        std::cin >> n >> s;
        for (int i = 1; i <= n; ++i) {
            pos_a[i] = pos_b[i] = 0;
            vis[i] = 0;
        }
        count = 0;
        ans = 1;
        st.clear();
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
            pos_a[a[i]] = i;
        }
        for (int i = 1; i <= n; ++i) {
            std::cin >> b[i];
            if (b[i] != -1) pos_b[b[i]] = i, vis[i] = 1;
        }
        
        for (int i = 1; i <= s; ++i) {
            if (vis[pos_a[i]]) st.insert(pos_a[i]);
            else ++count;
        }
        for (int i = s + 1; i <= n + s; ++i) {
            if (i <= n) {
                if (vis[pos_a[i]]) st.insert(pos_a[i]);
                else ++count;
            }
            if (!pos_b[i - s]) {
                ans *= count;
                ans %= mod;
                --count;
            } else {
                if (!st.count(pos_b[i - s])) {
                    ans = 0;
                }
                st.erase(pos_b[i - s]);
            }
        }
        std::cout << ans << '\n';
    }

    return 0;
}
// 17 : 00 - 17 : 34