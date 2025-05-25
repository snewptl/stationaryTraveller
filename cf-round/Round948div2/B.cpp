#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;
typedef double db;
typedef long double ldb;
const int maxn = 2e5 + 5;
int x, a[32];
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> x;
        for (int i = 0; i <= 31; ++i) a[i] = 0;
        int lst = -1;
        for (int i = 30; i >= 0; --i) {
            int cur = 1 << i;
            if(cur & x) {
                if (lst == -1) lst = i;
            } else {
                if (lst != -1) {
                    a[lst + 1] += 1;
                    a[i + 1] += -1;
                    lst = -1;
                } 
            }
        }
        std::cout << 32 << '\n';
        if (lst != -1) {
            a[lst + 1] += 1, a[0] += -1;
        }
        for (int i = 0; i < 31; ++i) {
            if (a[i + 1] * a[i] == -1) {
                if (a[i + 1] == -1) {
                    a[i + 1] = 0;
                    a[i] = -1;
                } else {
                    a[i + 1] = 0;
                    a[i] = 1;
                }

            }
        }
        
        for (int i = 0; i <= 31; ++i) std::cout << a[i] << ' ';
        std::cout << '\n';
    }


    return 0;
}
