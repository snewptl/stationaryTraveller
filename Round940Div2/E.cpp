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
const int maxn = 1e6 + 5;
const ll mod = 1e9 + 7;
const int N = 1e6;
ll n;
ll prefix[maxn];
int ans[maxn];
namespace Prime {
    int vis[maxn];
    std::vector<int>vec;
    void prepare() {
        for (int i = 2; i <= N; ++i) {
            if (!vis[i]) vec.push_back(i);
            for (int j = i * 2; j <= N; j += i) {
                vis[j] = 1;
            }
        }
    }
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    Prime::prepare();

    for (int i : Prime::vec) {
        for (int j = i; j <= N; j += i) {
            int add = (-(j / i % i) + i) % i;
            prefix[j] += add;
            prefix[j] %= mod;
            if (j + i <= N) {
                prefix[j + i] -= add;
                prefix[j + i] %= mod;
            }
        }
    }
    int i = 4;
    for (int j = i; j <= N; j += i) {
        int add = 2 * (j / i) % i;
        prefix[j] += add;
        prefix[j] %= mod;
        if (j + i <= N) {
            prefix[j + i] -= add;
            prefix[j + i] %= mod;
        }
    }

    ll res = 0;
    for (int i = 1; i <= N; ++i) {
        prefix[i] += prefix[i - 1];
        prefix[i] %= mod;
        res += prefix[i];
        res %= mod;
        ans[i] = (res + mod) % mod;
    }

    int T = 1;
    std::cin >> T;
    for (int i = 1; i <= T; ++i) {
        std::cin >> n;
        std::cout << ans[n] << '\n';
    }

    return 0;
}
