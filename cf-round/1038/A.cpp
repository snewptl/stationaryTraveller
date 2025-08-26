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
int count[26];
int n, k;
std::string s;
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    // std::cin >> T;
    while (T--) {
        std::cin >> n >> k >> s;
        for (int i = 0; i < k; ++i) count[i] = 0;
        for (int i = 0; i < s.size(); ++i) {
            count[s[i] - 'A'] += 1;
        }
        int num = n + 1;
        for (int i = 0; i < k; ++i) {
            num = std::min(num, count[i]);
        }
        std::cout << num * k << '\n';
    }

    return 0;
}
