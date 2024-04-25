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
int n, x;
std::map<int, int> vis;
int check(int i) {
    return (i + 2) / 2 >= x && i % 2 == 0 && !vis.count(i);
}
int countFactor(int cur) {
    int res = 0;
    for (int i = 1; i * i <= cur; ++i) {
        if (cur % i == 0) {
            if (check(i)) ++res, vis[i] = 1;
            if (i * i == cur) break;
            if (check(cur / i)) ++res, vis[cur / i] = 1;
        }
    }
    return res;
}
int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    std::cin >> T;
    while (T--) {
        vis.clear();
        std::cin >> n >> x;
        int res = countFactor(n - x);
        if (x != 1) res += countFactor(n + x - 2);
        std::cout << res << '\n';
    }

    return 0;
}
/*
1 2 ... k-1 k k-1 ... 2 1 2 
*/
