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
const int maxn = 5e3 + 5;
const ll mod = 998244353;
int n, k, p, m;
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
        std::cin >> n >> k >> p >> m;
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
        }
        std::vector<int> vec;
        for (int i = 1; i < p; ++i) {
            vec.push_back(a[i]);
        }
        std::sort(all(vec));
        ll sum = 0, turn = 0;
        for (int i = 0; i < p - k; ++i) {
            sum += vec[i];
        }
        sum += a[p];
        if (sum <= m) turn += 1;
        for (int i = p + 1; i <= n; ++i) {
            vec.push_back(a[i]);
        }
        std::sort(all(vec));
        int single_round = a[p];
        for (int i = 0; i < n - k; ++i) {
            single_round += vec[i];
        }
        if (sum <= m) {
            turn += (m - sum) / single_round;
        }
        std::cout << turn << '\n';
    }

    return 0;
}
