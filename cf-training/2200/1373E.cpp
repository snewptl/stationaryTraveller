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
const int maxn = 2e5 + 5;
const ll mod = 998244353;
int n, k;
std::string ans;
bool check(std::string a, std::string b) {
    if (a.size() > b.size()) return true;
    if (a.size() < b.size()) return false;
    return a > b;
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
        ans.clear();
        std::cin >> n >> k;
        for (int len = 0; len * 9 <= n; ++len) {
            for (int i = 0; i <= 9; ++i) {
                int sum = 0;
                for (int j = 0; j <= k; ++j) {
                    sum += (i + j) % 10;
                    sum += (i + j) / 10 ? 1 : len * 9;
                }
                if (sum > n) continue;
                if ((n - sum) % (k + 1) != 0) continue;
                int construct = (n - sum) / (k + 1);
                std::string s;
                s.push_back((char)(i + '0'));
                for (int j = 0; j < len; ++j) s.push_back('9');
                if (construct > 8) {
                    s.push_back('8');
                    construct -= 8;
                    while (construct >= 9) {
                        s.push_back('9');
                        construct -= 9;
                    } 
                    if (construct) s.push_back(construct + '0');
                } else if (construct) {
                    s.push_back(construct + '0');
                }
                for (int j = 0; j < s.size() / 2; ++j) std::swap(s[j], s[s.size() - j - 1]);
                if (ans.empty() || check(ans, s)) ans = s;
            }
        }
        if (ans.empty()) ans = "-1";
        std::cout << ans << '\n';
    }

    return 0;
}
// 17 : 05 - 17 : 40