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
ll a[maxn];
std::vector<int> vec;
ll pre[maxn], suf[maxn];
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
        vec.clear();
        std::cin >> n;
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
        }
        for (int i = 1; i <= n; ++i) {
            pre[i] = pre[i - 1] + std::abs(a[i]);
        }
        suf[n + 1] = 0;
        for (int i = n; i >= 1; --i) {
            if (i == n) suf[i] = a[i];
            else suf[i] = suf[i + 1] + a[i];
        }
        int pos = 0;
        ll max = suf[1];


        for (int i = 1; i <= n; ++i) {
            if (a[i] <= 0) continue;
            ll cur = pre[i - 1] + suf[i + 1] - a[i];
            if (cur > max) {
                max = cur;
                pos = i;
            }
        }

        if (pos) {
            int sgn = 1;
            for (int i = pos - 1; i >= 1; --i) {
                if (a[i] * sgn > 0) vec.push_back(i), sgn *= -1;
            }
            vec.push_back(pos);
        }
        
        std::cout << vec.size() << '\n';
        for (auto it : vec) {
            std::cout << it << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}
