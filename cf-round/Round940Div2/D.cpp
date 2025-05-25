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
int left[32][maxn], right[32][maxn];
int a[maxn];
int n;
int highBit(int x) {
    int cnt = 0;
    while(x) {
        x /= 2;
        cnt++;
    }
    return cnt - 1;
}
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
        std::cin >> n; 
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < 32; ++j) {
                int flag = (1 << j) & a[i];
                if (flag) {
                    left[j][i] = (i - 1 - left[j][i - 1]) + 1;
                } else {
                    left[j][i] = left[j][i - 1];
                }
            }
        }
        for (int i = 0; i < 32; ++i)
            right[i][n + 1] = 0;
        for (int i = n; i >= 1; --i) {
            for (int j = 0; j < 32; ++j) {
                int flag = (1 << j) & a[i];
                if (flag) {
                    right[j][i] = (n - i - right[j][i + 1]) + 1;
                } else {
                    right[j][i] = right[j][i + 1];
                }
            }
        }
        ll ans = 0;
        for (int i = 1; i <= n; ++i) {
            int j = highBit(a[i]);
            if (i > 1) {
                ans += 1ll * left[j][i - 1] * (n - i - right[j][i + 1] + 1);
            }
            if (i < n) {
                ans += 1ll * (i - 1 - left[j][i - 1] + 1) * right[j][i + 1];
            }
        }
        std::cout << ans << '\n';
    }

    return 0;
}
/*
y 最高的 1 在 f（x， z） 也有
*/