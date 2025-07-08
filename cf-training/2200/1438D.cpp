#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <assert.h>
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
int n, a[maxn];
std::vector<std::vector<int>> vec;
void operate(int x) {
    int res = 0;
    for (int i = x; i < x + 3; ++i) res ^= a[i];
    for (int i = x; i < x + 3; ++i) a[i] = res;
    vec.push_back(std::vector<int>{x, x + 1, x + 2});
}
void output() {
    std::cout << "YES\n";
    std::cout << vec.size() << '\n';
    for (auto it : vec) {
        for (auto that : it) {
            std::cout << that << ' ';
        }
        std::cout << '\n';
    }
}
bool solve() {
    if (n % 2 == 1) {
        for (int i = 1; i <= n - 2; i += 2) {
            operate(i);
        }
        for (int i = n - 4; i >= 1; i -= 2) {
            operate(i);
        }
        output();
        return true;
    }
    operate(1);
    for (int i = 4; i <= n; i += 2) {
        if (i + 2 <= n) {
            operate(i);
            operate(i - 1);
        } else if (i + 1 <= n) {
            operate(i - 1);
            operate(i - 2);
        }
    }
    if (a[n] != a[1]) return false;
    output();
    return true;

}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n;
    for (int i = 1; i <= n; ++i) std::cin >> a[i];
    if(!solve()) std::cout << "NO\n";

    return 0;
}

// 19 : 25 - 20 : 32