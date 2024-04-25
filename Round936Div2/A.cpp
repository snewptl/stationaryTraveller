#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;
typedef double db;
typedef long double ldb;
const int maxN = 2e5 + 5;
int n, a[maxN];
int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> n; 
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
        }
        std::sort(a + 1, a + n + 1);
        int pre = a[(n + 1) / 2], cnt = 0;
        for (int i = (n + 1) / 2; i <= n; ++i) {
            if (a[i] == pre) cnt++;
        }
        std::cout << cnt << '\n';
    }

    return 0;
}
