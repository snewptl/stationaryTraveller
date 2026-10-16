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
const int div = 500;
int count[505];
struct FW {
    int fw[maxn];
    
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("0_input.txt", "r", stdin);
    // freopen("0_output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int q = 1;
    std::cin >> q;
    while (q--) {
        std::string s;
        std::cin >> s;
        int x, k, t;
        if (s[0] == '+') {
            std::cin >> x >> k;
            if (k <= div) {
                count[k] += x;
            } else {
                lwall.insert({x, })
            }
        } else if (s[0] == '-') {
            std::cin >> x >> k;

        } else {
            std::cin >> t;

        }
    }

    return 0;
}
