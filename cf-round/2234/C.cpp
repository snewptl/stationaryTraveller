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
ll H[maxn], h[maxn], temp[maxn];
ll base = 0;
ll solve() {
    std::vector<pli> vec;
    vec.push_back({h[1], 1});
    ll ans = base - std::min(h[1], h[n]);
    for (int i = 2; i <= n; ++i) {
        int last = i;
        while (!vec.empty()) {
            auto [val, pos] = vec.back();
            if (h[i] >= val) {
                vec.pop_back();
                last = pos;
                if (!vec.empty()) {
                    ans += (i - last + 1) * (std::min(vec.back().first, h[i]) - val);
                }
            } else {
                break;
            }
        }
        vec.push_back({h[i], last});
    }
    return ans;
}
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
        base = 0;
        for (int i = 1; i <= n; ++i) {
            std::cin >> H[i];
            h[i] = H[i];
        }
        for (int i = 1; i <= n; ++i) {
            base += std::min(H[i % n + 1], H[i]);
        }
        for (int i = 1; i <= n; ++i) {
            std::cout << solve() << ' ';
            for (int j = 1; j < n; ++j) {
                temp[j] = h[j + 1];
            }
            temp[n] = h[1];
            for (int j = 1; j <= n; ++j) {
                h[j] = temp[j];
            }
        }
        std::cout << '\n';
    }

    return 0;
}
