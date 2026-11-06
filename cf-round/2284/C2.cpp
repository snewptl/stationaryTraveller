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
int n;

std::vector<int> vec;
void solve(int a, int b) {
    if (a == b) {
    } else if (std::__gcd(b - a, a) == 1) {
        vec.push_back(b - a);
    } else {
        int flag = 0;
        for (int i = a + 1;  i <= std::min(a * 2, b); ++i) {
            // std::cout << i << ' ' << std::__gcd(i, a) << ' ' << std::__gcd(i, b) << '\n';
            if (std::__gcd(i, a) == 1 && std::__gcd(i, b) == 1) {
                flag = 1;
                vec.push_back(i - a);
                vec.push_back(b - i);
                break;
            }    
        }
        if (!flag) {
            solve(a, b - 1);
            vec.push_back(1);
        }
    }
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("0_input.txt", "r", stdin);
    // freopen("0_output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    std::cin >> T;
    while (T--) {
        vec.clear();
        int a, b;
        std::cin >> a >> b;
        solve(a, b);

        std::cout << vec.size() << '\n';
        for (auto it : vec) {
            std::cout << it << ' ';
        }
        std::cout << '\n';

        
    }

    return 0;
}
