#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#define all(x) x.begin(), x.end()
typedef int64_t ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;
typedef double db;
typedef long double ldb;
const int maxn = 2e5 + 5;
ll k, x, a;
bool check() {
    ll current = 1, sum = 0;
    for (int i = 1; i <= x + 1; ++i) {
        if (current * (k - 1) <= sum)
            current = sum / (k - 1) + 1;
        if(current + sum > a) return false;
        sum += current;
    }
    return true;
}
int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> k >> x >> a;
        if(check()) std::cout << "YES\n";
        else std::cout << "NO\n";
    }

    return 0;
}
