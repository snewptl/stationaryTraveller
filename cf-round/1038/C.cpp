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
int n;
ll a[maxn], b[maxn];
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    // std::cin >> T;
    while (T--) {
        std::cin >> n;
        ll alice = 0, bob = 0;
        std::vector<ll> combined;
        for (int i = 1; i <= n; ++i) {
            ll x; 
            std::cin >> x;
            bob -= x;
            combined.push_back(x);
        }
        for (int i = 1; i <= n; ++i) {
            ll x; 
            std::cin >> x;
            alice -= x;
            combined.push_back(x);
        } 
        std::sort(all(combined));
        for (int i = 2 * n - 1; i >= 0; i -= 2) {
            alice += combined[i];
            bob += combined[i - 1];
        } 
        std::cout << alice << '\n';
    }

    return 0;
}
