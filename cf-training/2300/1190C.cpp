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
int k, n;
std::string s;
pii loc[2];
int prefix[2][maxn];
bool check(pii* l) {
    for (int i = 0; i < 2; ++i) {
        if (l[i].second - l[i].first + 1 <= k) return true;
    }
    return false;
}
bool is_in(int x, int i, int j) {
    return x >= i && x <= j;
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("0_input.txt", "r", stdin);
    // freopen("0_output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    // std::cin >> T;
    while (T--) {
        std::cin >> n >> k >> s;
        loc[0] = {n + 1, -1};
        loc[1] = {n + 1, -1};
        
        for (int i = 1; i <= n; ++i) {
            prefix[0][i] = prefix[0][i - 1];
            prefix[1][i] = prefix[1][i - 1];
            if (s[i - 1] == '0') {
                loc[0].first = std::min(loc[0].first, i);
                loc[0].second = std::max(loc[0].second, i);
                prefix[0][i] += 1;
            } else {
                loc[1].first = std::min(loc[1].first, i);
                loc[1].second = std::max(loc[1].second, i);
                prefix[1][i] += 1;
            }
        }
        if (check(loc)) std::cout << "tokitsukaze\n";
        else {
            int flag = 1;
            for (int i = 1; i + k - 1 <= n; ++i) {
                pii cur_loc[2];
                for (int j = 0; j < 2; ++j) {
                    cur_loc[j].first = std::min(loc[j].first, i);
                    cur_loc[j].second = std::max(loc[j].second, i);
                    cur_loc[j ^ 1] = loc[j ^ 1];
                    if (is_in(loc[j ^ 1].first, i, i + k - 1)) {
                        auto it = std::lower_bound(prefix[j ^ 1] + i + k, prefix[j ^ 1] + n + 1, 2);
                        cur_loc[j ^ 1].first = it - prefix[j ^ 1];
                    }
                    if (is_in(loc[j ^ 1].second, i, i + k - 1)) {
                        auto it = std::lower_bound(prefix[j ^ 1] + 1, prefix[j ^ 1] + i, prefix[j ^ 1][n] - 1);
                        if (prefix[j ^ 1][n] == 1 || it == prefix[j ^ 1] + i) cur_loc[j ^ 1].second = -1;
                        else cur_loc[j ^ 1].second = it - prefix[j ^ 1];
                    }
                    if (!check(cur_loc)) flag = 0;
                }
            }
            if (flag) {
                std::cout << "quailty\n";
            } else {
                std::cout << "once again\n";
            }
        }
    }

    return 0;
}
// 16 : 55 - 17 : 32