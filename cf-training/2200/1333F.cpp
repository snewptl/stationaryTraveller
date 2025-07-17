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
const int maxn = 5e5 + 5;
const ll mod = 998244353;
int n;
std::set<pii, std::greater<pii>>s;
std::vector<int> prime;
int vis[maxn], max_fac[maxn];
void get_prime() {
    max_fac[1] = 1;
    for (int i = 2; i <= n; ++i) {
        if (!vis[i]) prime.push_back(i), max_fac[i] = 1;
        for (auto it : prime) {
            if (it > n / i) break;
            vis[it * i] = 1;
            max_fac[it * i] = i;
            if (i % it == 0) break;
        }
    }
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n;
    get_prime();
    std::vector<int> res;
    for (int i = 1; i <= n; ++i) {
        s.insert({max_fac[i], i});
    } 
    for (int i = n; i >= 2; --i) {
        res.push_back(s.begin()->first);
        s.erase(s.begin());
    }
    std::reverse(all(res));
    for (auto it : res) {
        std::cout << it << ' ';
    }
    std::cout << '\n';
    

    return 0;
}
