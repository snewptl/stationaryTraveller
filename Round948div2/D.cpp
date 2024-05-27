#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;
typedef double db;
typedef long double ldb;
const int maxn = 3e5 + 5;
const int p1 = 13;
const ll mod = 1e9 + 7;
std::map<int, std::vector<int>> dp;
int n, m;
std::vector<int> a[maxn];
int facP1[maxn];
int final[maxn];
void print() {
    int finalAns = 0;
    for (int col = 0; col < m; ++col) {
        int tot = 0;
        for (int row = 0; row < n; ++row) {
            tot += final[row] ^ a[row][col];
        }
        finalAns += (tot == 1);
    }
    std::cout << finalAns << '\n';
    for (int i = 0; i < n; ++i) std::cout << (final[i] ? '1' : '0');
    std::cout << '\n';
}
void solve() {
    for (int i = 0; i < m; ++i) {
        ll num = 0;
        for (int j = 0; j < n; ++j) {
            if (a[j][i] == 1) num += facP1[j]; 
        }
        for (int j = 0; j < n; ++j) {
            if (a[j][i]) {
                dp[(num - facP1[j] + mod) % mod].push_back(i);
            } else {
                dp[(num + facP1[j]) % mod].push_back(i);
            }
        }
    }
    int ans = 0, originalNum = 0;
    std::vector<int> vec;
    for (auto it : dp) {
        if (ans < it.second.size()) {
            ans = std::max(ans, (int)it.second.size());
            originalNum = it.first;
            vec = it.second;
        }
    }
    // std::cout << ans << '\n';
    int i = vec[0];
    ll num = 0;
    for (int j = 0; j < n; ++j) {
        if (a[j][i] == 1) num += facP1[j]; 
    }
    for (int j = 0; j < n; ++j) {
        if (a[j][i]) {
            if ((num - facP1[j] + mod) % mod == originalNum) {
                for (int k = 0; k < n; ++k) {
                    if (a[k][i]) {
                        if (k == j) final[k] = 0;
                        else final[k] = 1;
                    } else {
                        final[k] = 0;
                    }
                }
                // std::cout << '\n';
                print();
                return;
            }
        } else {
            if ((num + facP1[j]) % mod == originalNum) {
                for (int k = 0; k < n; ++k) {
                    if (!a[k][i]) {
                        if (k == j) final[k] = 1;
                        else final[k] = 0;
                    } else {
                        final[k] = 1;
                    }
                }
                // std::cout << '\n';
                print();
                return;
            }
        }
    }
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    facP1[0] = 1;
    for (int i = 1; i <= 3e5; ++i) {
        facP1[i] = 1ll * facP1[i - 1] * p1 % mod;
    }
    int T = 1;
    std::cin >> T;
    while (T--) {
        dp.clear();
        std::cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            a[i].clear();
            std::string s;
            std::cin >> s;
            for (int j = 0; j < m; ++j) {
                a[i].push_back(s[j] - '0');
            }
        }
        solve();
    }

    return 0;
}
