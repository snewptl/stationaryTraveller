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
const int maxn = 3e5 + 5;
const ll mod = 998244353;
std::string s;
int solve() {
    int max = 0, count = 0, mid = 0;
    int state = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '<') {
            if (state != 0) return -1;
            count += 1;
        } else if (s[i] == '*') {
            mid = 1;
            if (state == 0) {
                max = std::max(max, count);
                state = 1;
                count = 0;
            } else {
                return -1;
            }
        } else {
            if (state != 2) {
                max = std::max(max, count);
                state = 2;
                count = 1;
            } else {
                count += 1;
            }

        }
    }
    max = std::max(max, count);
    return max + mid;
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
        std::cin >> s;
        std::cout << solve() << '\n';
    }

    return 0;
}
