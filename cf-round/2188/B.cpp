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
bool can(int i) {
    if (i >= n) return false;
    if ((i == 0 || s[i - 1] == '0') && (i == n - 1 || s[i + 1] == '0')) return true;
    return false;
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
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') continue;
            if (can(i)) {
                if (can(i + 1)) s[i + 1] = '1';
                else s[i] = '1';
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') cnt += 1;
        }
        std::cout << cnt << '\n';
    }

    return 0;
}
