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
int a[maxn], b[maxn];
std::string ans;
bool check(int pos) {
    int flag = 1;
    for (int i = 1; i < 5; ++i) {
        if (b[pos + i] > b[pos + i - 1]) flag = 0;
    }
    if (flag) return true;
    flag = 1;
    for (int i = 1; i < 5; ++i) {
        if (b[pos + i] < b[pos + i - 1]) flag = 0;
    }
    return flag;
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
        ans.clear();
        for (int i = 1; i <= n; ++i) std::cin >> a[i];
        ans.push_back('#');
        for (int i = 1; i <= n / 2; ++i) {
            ans.push_back('L');
            ans.push_back('R');
            b[i * 2 - 1] = a[i];
            b[i * 2] = a[n - i + 1];
        }
        if (n % 2) ans.push_back('L'), b[n] = a[n / 2 + 1];
        for (int i = 1; i <= n - 5; ++i) {
            if (check(i)) {
                std::swap(ans[i + 3], ans[i + 4]);
                std::swap(b[i + 3], b[i + 4]);
            }
        }
        if (check(n - 4)) {
            std::swap(ans[n - 1], ans[n - 2]);
            std::swap(b[n - 1], b[n - 2]);
        }
        for (int i = 0; i < n; ++i) std::cout << ans[i + 1];
        std::cout << '\n';
    }

    return 0;
}
