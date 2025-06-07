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
typedef unsigned long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;
typedef double db;
typedef long double ldb;
const int maxn = 2e5 + 5;
const ll mod = 998244353;
ll s, k, ans;
ll digit[10];
const int cycle = 4;
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
        std::cin >> s >> k;
        if (s % 10 == 0) {
            std::cout << k * s << '\n';
            continue;
        } else if (s % 10 == 5) {
            if (!k) std::cout << "0\n";
            else std::cout << std::max(k * s, (k - 1) * (s + 5)) << '\n';
            continue;
        }
        ans = 0;
        ll cur = s;
        memset(digit, 0, sizeof(digit));
        for (ll i = 0; i <= std::min(k, 9ull); ++i) {
            digit[cur % 10] = std::max(digit[cur % 10], (k - i) * cur);
            cur += cur % 10;
        }
        for (ll i = 2; i <= 8; i += 2) {
            cur = s;
            long long time = k;
            while (cur % 10 != i) {
                cur += cur % 10;
                --time;
            }
            if (time < 0) continue;
            ll l = 0, r = time / cycle;
            while (r - l + 1 > 3) {
                ll m1 = l + (r - l) / 3;
                ll m2 = r - (r - l) / 3;
                if ((cur + 20 * m1) * (time - cycle * m1) < (cur + 20 * m2) * (time - cycle * m2))  l = m1 + 1;
                else r = m2;
            }
            ll res = 0;
            for (ll j = l; j <= r; ++j) res = std::max(res, (cur + 20 * j) * (time - cycle * j));
            digit[i] = std::max(digit[i], res);
        
        }
        for (int i = 1; i <= 9; ++i) ans = std::max(ans, digit[i]);
        std::cout << ans << '\n';
    }

    return 0;
}
/*
2 4 8 6 2
*/