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
const int maxn = 1e6 + 5;
const ll mod = 998244353;
int n;
std::string s;
int a[maxn];
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
        std::cin >> n >> s;
        int count = 0, last = 0;
        for (int i = 0; i < n; ++i) {
            a[i] = s[i] - '0';
        }
        for (int i = 0; i < n - 2; ++i) {
            count += s[i] - '0';
            if (!last && count) {
                last = 1;
                count -= 1;
                a[i] = 1;
            } else {
                a[i] = 0;
                last = 0;
            }
        }
        if (count && n > 3) {
            a[n - 3] = a[n - 4] = 1;   
        }
        int flag = 1;
        int check = (n < 4 || !a[n - 4]) && (n < 5 || (!a[n - 5] || !a[n - 3]));
        if (a[n - 2]) {
            if (check) {
                flag = 0;
            }
        }
        if (a[n - 1]) {
            if ((!a[n - 2] && !a[n - 3]) || check) {
                flag = 0;
            }
        }
        if (flag) std::cout << "Yes\n";
        else std::cout << "No\n";
    }

    return 0;
}
