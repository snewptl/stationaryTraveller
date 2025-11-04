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
int a[maxn];
int ask(int pos, int x) {
    return (a[pos] & x) >= 1;
}
int n;
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
        for (int i = 1; i <= n; ++i) std::cin >> a[i];
        std::vector<int> vec[3];
        for (int i = 1; i < n; ++i) {
            vec[2].push_back(i);
        }
        int sum = 0;
        for (int i = 1; i <= n; i *= 2) {
            int ones = n / (i * 2) + (n % (i * 2) >= sum + i);
            // int zeroes = n - ones;
            int count[2] = {0, 0};
            for (auto j : vec[2]) {
                int res = ask(j, i);
                count[res] += 1;
                vec[res].push_back(j);
            }
            if (vec[1].size() == ones) { // 0
                vec[2] = vec[0];
            } else {
                sum += i;
                vec[2] = vec[1];
            }
            vec[0].clear();
            vec[1].clear();
        }
        std::cout << "! " << sum << '\n';
    }

    return 0;
}
