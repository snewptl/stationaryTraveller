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
int n, a[maxn];
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
        for (int i = 1; i <= n; ++i) std::cin >> a[i];
        std::sort(a + 1, a + n + 1);
        int left = 2; 
        while (left <= n && a[left] % 2 == a[1] % 2) ++left;
        int right = n - 1;
        while (right && a[right] % 2 == a[n] % 2) --right;
        if (a[1] % 2 == a[n] % 2) std::cout << "0\n";
        else std::cout << std::min(left - 1, n - right) << '\n';
    }

    return 0;
}
