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
const int maxn = 3e5 + 5;
const ll mod = 998244353;
int n;
ll a[maxn];
ll pre[maxn], nxt[maxn];
ll sum = 0;
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
        sum = 0;
        for (int i = 1; i <= n; ++i) std::cin >> a[i], sum += a[i];
        std::vector<pii> vec;
        for (int i = 1; i <= n; ++i) {
            ll temp = 0;
            while (!vec.empty()) {
                auto [val, pos] = vec.back();
                if (a[i] - (i - pos) <= val) vec.pop_back();
                else {
                    temp = pre[pos] + (a[i] - (i - pos - 1) + a[i] - 1) * (i - pos - 1) / 2 + val; 
                    break;
                }
            }
            if (vec.empty()) {
               if (a[i] >= i) temp = (a[i] - (i - 1) + a[i] - 1) * (i - 1) / 2;
               else temp = (a[i] - 1 + 1) * (a[i] - 1) / 2;
            }
            pre[i] = temp;
            vec.push_back({a[i], i});
        }
        vec.clear();
        for (int i = n; i >= 1; --i) {
            ll temp = 0;
            while (!vec.empty()) {
                auto [val, pos] = vec.back();
                if (a[i] - (pos - i) <= val) vec.pop_back();
                else {
                    temp = nxt[pos] + (a[i] - (pos - i - 1) + a[i] - 1) * (pos - i - 1) / 2 + val;
                    break;
                }
            }
            if (vec.empty()) {
               if (a[i] > n - i) temp = (a[i] - (n - i) + a[i] - 1) * (n - i) / 2;
               else temp = (a[i] - 1 + 1) * (a[i] - 1) / 2;
            }
            nxt[i] = temp;
            vec.push_back({a[i], i});
        }
        ll temp = 0;
        for (int i = 1; i <= n; ++i) {
            temp = std::max(temp, pre[i] + nxt[i]);
        }
        std::cout << sum - temp << '\n';
    }

    return 0;
}
