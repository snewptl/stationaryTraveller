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
const int maxn = 2e5 + 5;
int n;
std::string s[2];
int main() {
    #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> n >> s[0] >> s[1];
        int count = 0;
        for (int i = 1; i < n - 1; ++i) {
            if (s[0][i] == s[1][i] && s[0][i] == '.') {
                if (s[0][i - 1] == s[0][i + 1] && s[1][i - 1] == s[1][i + 1]) {
                    if (s[0][i - 1] != s[1][i - 1]) count ++;
                }
            }
        }
        std::cout << count << '\n';
    }

    return 0;
}
