#include <iostream>
#include <cstdio>
#include <cmath>
#include <set>
#include <cmath>
#include <assert.h>
#include <memory.h>
#include <queue>
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef std::pair<int, int> pii;
const int maxn = 2e5 + 5;
ll a, b, c;
int main() {
    #ifndef ONLINE_JUDGE
    freopen("0_input.txt", "r", stdin);
    freopen("0_output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> a >> b >> c;
        while (b) {
            a += b;
            if (a + b / 2 > c) b /= 4;
            else b /= 2;
        }
        if (a == c) std::cout << "YES\n";
        else std::cout << "NO\n";
    }
}