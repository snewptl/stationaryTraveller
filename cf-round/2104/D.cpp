#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <bitset>
#include <memory.h>
#include <assert.h>
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;
typedef double db;
typedef long double ldb;
const int maxn = 2e7 + 5;
const ll mod = 998244353;
bool vis[maxn], is_prime[maxn];
std::vector<ll> vec;
int n;
ll a[400005], sum[400005];
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    for (int i = 2; i <= 2e7; ++i) {
        if (!vis[i]) vec.push_back(i), is_prime[i] = 1;
        if (vec.size() >= 4e5) break;
        for (auto it : vec) {
            if (1ll * it * i > 2e7) break;
            vis[1ll * it * i] = 1;
            if (i % it == 0) break;
        }
    }
    assert(vec.size() >= 4e5);
    for (int i = 1; i < 4e5; ++i)  vec[i] += vec[i - 1];
    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> n;
        for (int i = 1; i <= n; ++i) std::cin >> a[i];
        std::sort(a + 1, a + n + 1);
        for (int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + a[i];
        for (int i = 1; i <= n; ++i) {
            if (sum[n] - sum[i - 1] >= vec[n - i]) {
                std::cout << i - 1 << '\n';
                break;
            }
        }
    }

    return 0;
}
