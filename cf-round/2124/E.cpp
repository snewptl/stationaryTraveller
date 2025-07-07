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
const int maxn = 5e4 + 5;
const ll mod = 998244353;
int n;
ll a[maxn], sum[maxn];
bool solve() {
    if (sum[n] % 2) return false;
    for (int i = n; i >= 1; --i) {
        if (sum[i - 1] <= sum[n] - sum[i - 1]) {
            if (sum[i - 1] == sum[n] - sum[i - 1]) {
                std::cout << "1\n";
                for (int j = 1; j <= n; ++j) {
                    std::cout << a[j] << ' ';
                }
                std::cout << '\n';
                return true;
            } else {
                ll delta = (sum[n] - sum[i - 1]) - sum[i - 1];
                assert(delta <= 2 * a[i]);
                if (sum[n] - sum[i] < delta / 2) return false;
                std::cout << "2\n";
                ll remain = delta / 2;
                for (int j = 1; j < i; ++j) std::cout << "0 ";
                std::cout << remain << ' ';
                a[i] -= remain;
                for (int j = i + 1; j <= n; ++j) {
                    ll temp = std::min(a[j], remain);
                    remain -= temp;
                    a[j] -= temp;
                    std::cout << temp << ' ';
                }
                std::cout << '\n';
                for (int j = 1; j <= n; ++j) {
                    std::cout << a[j] << ' ';
                }
                std::cout << '\n';
                return true;
            }
        }
    }
    return false;
}
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
        for (int i = 1; i <= n; ++i) std::cin >> a[i];
        for (int i = 1; i <= n; ++i) {
            sum[i] = sum[i - 1] + a[i];
        }
        if (!solve()) std::cout << "-1\n";
    }

    return 0;
}
