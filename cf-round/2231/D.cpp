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
std::string s;
ll a[maxn];
ll c[maxn];
bool solve() {
    int last = 1;
    for (int i = 1; i <= n; ++i) {
        if (i != 1 && c[i] < c[i - 1]) return false;
        if (i == 1 || c[i] > c[i - 1]) {
            ll delta = c[i] - c[i - 1];
            if (s[i - 1] == '1' && a[i] < delta) return false;

            int l = n + 1, r = 0;
            for (int j = last; j <= i; ++j) {
                if (s[j - 1] == '0') l = std::min(l, j), r = std::max(r, j);
            }

            ll sum = 0, max = -1e18;
            for (int j = last; j < i; ++j) {
                if (s[j - 1] == '1') {
                    sum += a[j];
                    max = std::max(max, sum);
                }
            }
            if (l <= r) {
                if (max > 0) a[l] -= max;
                if (s[i - 1] == '1') a[l] -= a[i] - delta;
                ll new_sum = 0;
                for (int j = last; j <= i; ++j) {
                    new_sum += a[j];
                }
                if (new_sum != delta) a[r] += delta - new_sum;
            }

            ll new_sum = 0;
            for (int j = last; j < i; ++j) {
                new_sum += a[j];
                if (new_sum > 0) return false;
            }
            new_sum += a[i];
            if (new_sum != delta) return false;

            last = i + 1;
        }
    }
    ll sum = 0;
    if (last <= n) {
        while (last <= n && s[last - 1] == '1') {
            sum += a[last];
            if (sum > 0) return false;
            last += 1;
        }
        if (last <= n) {
            a[last] = -1e18;
        }
    }
    std::cout << "YES\n";
    for (int i = 1; i <= n; ++i) std::cout << a[i] << ' ';
    std::cout << '\n';
    return true;
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
        std::cin >> n >> s;
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
        }
        for (int i = 1; i <= n; ++i) {
            std::cin >> c[i];
        }
        if(!solve()) std::cout << "NO\n";
    }

    return 0;
}
