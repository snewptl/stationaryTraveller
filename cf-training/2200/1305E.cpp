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
int n, m;
std::vector<int> vec;
void solve() {
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        int add = (i - 1) / 2;
        if (add + sum < m) {
            vec.push_back(i);
            sum += add;
        } else {
            int delta = m - sum;
            vec.push_back(i + (add - delta) * 2);
            int sz = vec.size();
            for (int i = 1; i <= n - sz; ++i) {
                vec.push_back(i * 20001 - 1);
            }
            for (auto it : vec) std::cout << it << ' ';
            std::cout << '\n';
            return;
        }
    }
    std::cout << "-1\n";
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> m;
    solve();


    return 0;
}
// m <= 0 corner case

// 11 : 58 - 12 : 47