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
const int maxn = 1e6 + 5;
const ll mod = 998244353;
int n, k_max, k_min;
std::string s, t;
std::vector<char> mp[maxn];
int loc[maxn], pos[maxn];
bool solve() {
    int last = n - 1;
    for (int i = n - 1; i >= 0; --i) {
        if (last > i) last = i;
        while (last >= 0 && s[last] != t[i]) {
            --last;
        }
        if (last == -1) return false;
        loc[i] = last;
        pos[last] = std::max(pos[last], i);
        k_min = std::max(k_min, i - last);
    }
    if (k_min > k_max) return false;
    // for (int i = 0; i < n; ++i) {
    //     for (int j = 1; j <= k_min; ++j) {
    //         mp[j][i] = s[i];
    //     }
    // }
    // for (int i = 0; i < n; ++i) mp[0][i] = s[i];
    // for (int i = 0; i < n; ++i) {
    //     for (int j = 1; j <= i - loc[i]; ++j) {
    //         mp[j][loc[i] + j] = t[i];
    //     }
    //     for (int j = i - loc[i] + 1; j <= k_min; ++j) {
    //         mp[j][i] = t[i];
    //     }
    // }
    // for (int i = 1; i <= k_min; ++i) {
    //     for (int j = 1; j < n; ++j) {
    //         assert (mp[i][j] == mp[i - 1][j] || mp[i][j] == mp[i - 1][j - 1]);
    //     }
    //     assert(mp[i][0] == mp[i - 1][0]);
    // }
    for (int i = 0; i < n; ++i) mp[0][i] = s[i];
    for (int i = 1; i <= k_min; ++i) {
        for (int j = n - 1; j >= 0; --j) {
            mp[i][j] = mp[i - 1][j];
            if (pos[j] != -1 && pos[j] > j) {
                pos[j + 1] = pos[j];
                mp[i][j + 1] = mp[i][j];
            }
        }
    }
    for (int i = 1; i <= k_min; ++i) {
        for (int j = 1; j < n; ++j) {
            assert (mp[i][j] == mp[i - 1][j] || mp[i][j] == mp[i - 1][j - 1]);
        }
        assert(mp[i][0] == mp[i - 1][0]);
    }
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
        std::cin >> n >> k_max >> s >> t;
        k_min = 0;
        for (int i = 0; i <= k_max; ++i) {
            mp[i].resize(n + 10);
        }
        for (int i = 0; i < n; ++i) {
            pos[i] = -1;
        }
        if(solve()) {
            std::cout << k_min << '\n';
            for (int i = 1; i <= k_min; ++i) {
                for (int j = 0; j < n; ++j) {
                    std::cout << mp[i][j];
                }
                std::cout << '\n';
            }
        } else {
            std::cout << "-1\n";
        }



    }

    return 0;
}
