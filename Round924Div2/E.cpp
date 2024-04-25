#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#define all(x) x.begin(), x.end()
typedef int64_t ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;
typedef double db;
typedef long double ldb;
const int maxn = 2e5 + 5;
ll n, x, y, s;
int dp[maxn], lastSegment[maxn];
int ans[maxn];
int sigma(int x) {
    return x * (x - 1) / 2;
}
void prepareDP() {
    dp[0] = 0;
    for (int i = 1; i <= 2e5; ++i) {
        dp[i] = 1e9;
        for (int j = 2; sigma(j) <= i; ++j) {
            if (dp[i] > dp[i - sigma(j)] + j) {
                dp[i] = dp[i - sigma(j)] + j;
                lastSegment[i] = j;
            }
        }
    }
}
bool solve() {
    int basic = x % y;
    s -= basic * n;
    if (s < 0 || s % y != 0)
        return false;
    s /= y;
    x /= y;
    for (int i = 1; i <= n; ++i) {
        ll currentS = s - (x + x + i - 1) * i / 2;
        if (currentS < 0)
            break;
        if (i + dp[currentS] <= n) {
            std::vector<int> vec;
            while (currentS) {
                int start = lastSegment[currentS];
                currentS -= sigma(start);
                while (start) {
                    vec.push_back((start - 1) * y + basic);
                    --start;
                }
            }
            while (vec.size() < n - i)
                vec.push_back(basic);
            for (int j = i; j >= 1; --j) {
                vec.push_back(basic + (j - 1 + x) * y);
            }
            std::reverse(all(vec));
            for (int i = 1; i <= n; ++i)
                ans[i] = vec[i - 1];
            return true;
        }
    }
    return false;
}
int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    std::cin >> T;
    prepareDP();
    while (T--) {
        std::cin >> n >> x >> y >> s;
        if (solve()) {
            std::cout << "YES\n";
            for (int i = 1; i <= n; ++i)
                std::cout << ans[i] << ' ';
            std::cout << '\n';
        } else {
            std::cout << "NO\n";
        }
    }

    return 0;
}
