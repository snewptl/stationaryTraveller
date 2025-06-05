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
int n, k;
int vis[maxn];
void ask(int x) {
    int res;
    std::cout << "? " << x << std::endl;
    std::cin >> res;
    vis[x] = res;
}

int ans;
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
        std::cin >> n >> k;
        ans = 0;
        if (n < 2 * k) {
            ask(n - k + 1);
            ans ^= vis[n - k + 1];
            for (int i = n - k; i >= 1; i -= 2) {
                ask(i);
                ask(i - 1);
                ans ^= vis[i];
                ans ^= vis[i - 1];
            }
        } else {
            for (int i = 1; i + k - 1 <= n; i += k) {
                ask(i);
                ans ^= vis[i];
            }
            int remain = n % k;
            if (remain) {
                ask(n - k + 1);
                ans ^= vis[n - k + 1];
                ask(n - k + 1);
                ask(n - 2 * k + 1);
                ans ^= vis[n - 2 * k + 1];
                ask(n - 2 * k + 1);
                ask(n - k + 1 - remain / 2);
                ans ^= vis[n - k + 1 - remain / 2];
                ask(n - 2 * k + 1);
                ans ^= vis[n - 2 * k + 1];
            }
        }
        std::cout << "! " << ans << std::endl;
        
    }

    return 0;
}
/*

[a, a + k) [a + m, a + k + m)

[a + k ]

t * k / (k + 1 ) = 2

k = 4

1 2 3 4 5 6 7 8 9 10 n + 4

1 2 3 4 5 9 8 7 6 10 : 6 ^ 10 n + 5

1 2 9 5 4 3 8 7 6 10 : 6 ^ 9 -> 9 ^ 10 n + 6


k = 6

1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16:  n + 4  [5 6 7 8 9 10] [11 12 13 14 15 16]

1 2 3 4 5 6 7 8 14 13 12 11 10 9 15 16:  n + 5  [14 13 12 11 10 9] 10 ^ 9 ^ 15 ^ 16

1 2 3 4 5 6 7 8 14 13 12 11 10 9 15 16:  n + 6 [5 6 7 8 14 13] 14 ^ 13 


k = 4

n < 2 * k

1 2 3 4 5 6  

1 2 6 5 4 3 [3 4 5 6]

1 4 5 6 2 3 [4 5 6 2]

6 5 4 1 2 3 [1 4 5 6]
*/