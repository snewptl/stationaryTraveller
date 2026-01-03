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
std::vector<ll> even, odd;
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
        even.clear();
        odd.clear();
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
            if (a[i] % 2) {
                odd.push_back(a[i]);
            } else {
                even.push_back(a[i]);
            }
        } 
        std::sort(all(odd));
        std::sort(all(even));
        std::reverse(all(odd));
        std::reverse(all(even));
        for (int i = 1; i < odd.size(); ++i) {
            odd[i] += odd[i - 1];
        }
        for (int i = 1; i < even.size(); ++i) {
            even[i] += even[i - 1];
        }
        for (int i = 1; i <= n; ++i) {
            int need_odd = i - even.size();
            if (need_odd <= 0) need_odd = 0;
            if (need_odd % 2 != 1) need_odd += 1;
            int need_even = i - need_odd;
            if (odd.size() < need_odd || need_even < 0) {
                std::cout << "0 ";
            } else {
                ll add = 0;
                if (need_even) add = even[need_even - 1];
                std::cout << odd[0] + add << ' ';
            }
        }
        std::cout << '\n';

    }

    return 0;
}
