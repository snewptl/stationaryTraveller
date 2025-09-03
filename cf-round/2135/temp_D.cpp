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
const int mx = 1e5;
int w;
int l, r;
int fin = 20;
int ask(std::vector<int>& vec) {
    std::cout << "? " << vec.size() << ' ';
    for (auto it : vec) std::cout << it << ' ';
    std::cout << std::endl;
    int res;
    std::cin >> res;
    
    return res;
}
void output() {
    std::cout << "! " << w << std::endl;
}
void solve() {
    std::vector<int> vec;
    for (int i = 1; i <= mx; ++i) vec.push_back(1);
    int len1 = ask(vec);
    if (len1 == 1) {
        w = mx;
        output();
        return;
    }
    if (len1 == mx) {
        w = 1;
        output();
        return;
    }
    l = (mx + len1 - 1) / len1;
    r = (mx + len1 - 1 - 1) / (len1 - 1) - 1;
    if (l == r) {
        w = l;
        output();
        return;
    }
    for (int i = 1; i + l <= r; ++i) {
        for (int j = 20; j >= 0; --j) {
            if ((1 << j) & i) vec.push_back(1 << j);
        }
        vec.push_back(l);
    }
    int res = ask(vec) - (r - l);
    w = r - res;
    output();
}
int main() {
    #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    std::cin >> T;
    while (T--) {
        
        solve();


    }

    return 0;
}
