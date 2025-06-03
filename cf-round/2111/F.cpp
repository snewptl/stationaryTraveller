#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <cmath>
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;
typedef double db;
typedef long double ldb;
const int maxn = 2e5 + 5;
int p, s;
void solve() {
    for (int S = s, P = p; S <= 50000; S += s, P += p) {
        int width = std::sqrt(S);
        int length = S / width;
        int new_p = (width + length) * 2;
        std::vector<std::vector<int>> ans;
        int end = width;

        if (width * length != S) {
            new_p += 2;
            end = width + 1;
        }
        if (P % 2 != new_p % 2 || P < new_p || P > 2 * S + 2) continue;
        ans.resize(S + 1);
        for (int i = 1; i <= width; ++i) {
            for (int j = 1; j <= length; ++j) {
                ans[i].push_back(j);
            }
        }
        for (int i = 1; i <= S - width * length; ++i) {
            ans[width + 1].push_back(i);
        }
        int col = end;
        while (P > new_p) {
            while (col && ans[col].size() <= 1) --col;
            if (col == 0) break;
            ans[col].pop_back();
            ++end;
            ans[end].push_back(1);
            new_p += 2;
        }
        if (P == new_p) {
            std::cout << S << '\n';
            for (int i = 1; i <= end; ++i) {
                for (auto it : ans[i]) {
                    std::cout << i << ' ' << it << '\n';
                }
            }
            return;
        }
    } 
    std::cout << "-1\n";
}
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
        std::cin >> p >> s;
        int gcd = std::__gcd(p, s);
        p /= gcd, s /= gcd;
        solve();
    }

    return 0;
}
