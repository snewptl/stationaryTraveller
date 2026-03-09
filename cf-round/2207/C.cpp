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
const int maxn = 2e3 + 5;
const ll mod = 998244353;
int n, h;
ll a[maxn];
ll pre[maxn], nxt[maxn];
ll min;
ll all;
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
        std::cin >> n >> h;
        all = 0;
        min = 1e18;
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
            all += h - a[i];
        }
        for (int i = 1; i <= n; ++i) {
            ll cur = a[i];
            pre[i] = 0;
            for (int j = i - 1; j >= 1; --j) {
                cur = std::max(a[j], cur);
                pre[i] += cur - a[j];
            }
        }
        for (int i = n; i >= 1; --i) {
            ll cur = a[i];
            nxt[i] = 0;
            for (int j = i + 1; j <= n; ++j) {
                cur = std::max(a[j], cur);
                nxt[i] += cur - a[j];
            }
        }
        if (n == 1) min = 0;
        else {
            for (int i = 1; i <= n; ++i) {
                std::vector<pli> vec;
                vec.push_back({a[i], i});
                ll res = 0;
                for (int j = i + 1; j <= n; ++j) {
                    while (true) {
                        auto it = vec.back();
                        if (it.first > a[j]) {
                            vec.push_back({a[j], j});
                            break;
                        }  else if (it.first == a[j]) {
                            break;
                        } else {
                            vec.pop_back();
                            if (vec.empty()) {
                                vec.push_back({a[j], j});
                                break;
                            } else {
                                res += (std::min(vec.back().first, a[j]) - it.first) * (j - it.second);
                            }
                        }
                    }
                    min = std::min(res + pre[i] + nxt[j], min);
                }
            }
        }
        std::cout << all - min << '\n';
    }

    return 0;
}
