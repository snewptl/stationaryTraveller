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
int n;
std::string s[2];
int cnt[2];
bool solve() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2; ++j) {
            if (s[j][i] == '(') cnt[j] += 1;
            else cnt[j] -= 1;
        }
        
        for (int j = 0; j < 2; ++j) {
            if (cnt[j] < 0) {
                if (cnt[j ^ 1] <= 2) return false;
                cnt[j ^ 1] -= 2;
                cnt[j] += 2;
            }
        }
    }
    if (cnt[0] != cnt[1] || cnt[0] != 0) return false;
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
        std::cin >> n;
        std::cin >> s[0] >> s[1];
        cnt[0] = cnt[1] = 0;
        if (solve()) std::cout << "YES\n";
        else std::cout << "NO\n";

        
    }

    return 0;
}
