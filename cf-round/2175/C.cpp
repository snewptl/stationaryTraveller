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
std::string s[2];
int count[2][27];
bool solve() {
    for (int i = 0; i < 26; ++i) {
        if (count[0][i] > count[1][i]) {
            return false;
        }
        count[1][i] -= count[0][i];
    }
    for (int i = 0; i < s[0].size(); ++i) {
        int end = s[0][i] - 'a' - 1;
        if (i < s[0].size() - 1 && s[0][i + 1] > s[0][i]) end += 1;
        for (int j = 0; j <= end; ++j) {
            for (int k = 1; k <= count[1][j]; ++k) {
                std::cout << (char)(j + 'a');
            }
            count[1][j] = 0;
        }
        std::cout << s[0][i];
    }
    for (int j = 0; j < 26; ++j) {
        for (int k = 1; k <= count[1][j]; ++k) {
            std::cout << (char)(j + 'a');
        }
        count[1][j] = 0;
    }
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
        std::cin >> s[0] >> s[1];
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 26; ++j) {
                count[i][j] = 0;
            }
            for (int j = 0; j < s[i].size(); ++j) {
                count[i][s[i][j] - 'a'] += 1;
            }
        }
        if (!solve()) std::cout << "Impossible\n";
    }

    return 0;
}
