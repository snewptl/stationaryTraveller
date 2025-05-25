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
        std::cin >> n;
        int m = n / 5;
        int k = n % 5;
        char s[5] = {'a', 'e', 'i', 'o', 'u'};
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < m; ++j) {
                std::cout << s[i];
            }
            if (k) {
                --k;
                std::cout << s[i];
            }
        }
        std::cout << '\n';
    }

    return 0;
}
