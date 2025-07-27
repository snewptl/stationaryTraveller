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
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;
typedef double db;
typedef long double ldb;
const int maxn = 2e5 + 5;
const ll mod = 998244353;
std::string s;
int count[26];
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
        std::cin >> s;
        for (int i = 0; i < 26; ++i) count[i] = 0;
        for (int i = 0; i < s.size(); ++i) {
            count[s[i] - 'A']++;
        }
        for (int j = 0; j < count['T' - 'A']; ++j) {
            std::cout << (char)('T');
        }        
        for (int i = 0; i < 26; ++i) {
            if (i == 'T' - 'A') continue;
            for (int j = 0; j < count[i]; ++j) {
                std::cout << (char)(i + 'A');
            }
        }
        std::cout << '\n';
    }

    return 0;
}
