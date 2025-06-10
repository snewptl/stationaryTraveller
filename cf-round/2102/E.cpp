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
const int maxn = 2e5 + 5;
const ll mod = 998244353;
int n, a[maxn];
ll last_pre[maxn], sum_pre[maxn], last_nxt[maxn], sum_nxt[maxn];
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
        for (int i = 1; i <= n; ++i) {
            last_pre[i] = last_nxt[i] = 0;
        }
        for (int i = 1; i <= n; ++i) std::cin >> a[i];
        std::set<int> s;
        for (int i = 1; i <= n; ++i) s.insert(i);
        for (int i = 1; i <= n; ++i) {
            auto it = s.upper_bound(a[i]);
            if (it == s.begin()) continue;
             --it;
            s.erase(it);
            int idx = n - s.size();
            last_pre[idx] = i;
            sum_pre[idx] = sum_pre[idx - 1] + i;  
        }
        for (int i = 1; i <= n; ++i) s.insert(i);
        for (int i = n; i >= 1; --i) {
            auto it = s.upper_bound(a[i]);
            if (it == s.begin()) continue;
             --it;
            s.erase(it);
            int idx = n - s.size();
            last_nxt[idx] = i;
            sum_nxt[idx] = sum_nxt[idx - 1] + i;  
        }       
        for (int i = n; i >= 1; --i) {
            if (last_pre[i] && last_nxt[i] >= last_pre[i]) {
                std::cout << sum_nxt[i] - sum_pre[i] << '\n';
                break;
            }
        }
    }

    return 0;
}


