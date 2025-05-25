#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <memory.h>
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
int n, a[maxn];
ll sum, average;
pii count[2][32];
int lowbit(int x) {
    return x & -x;
}
int modify(int x) {
    int res = 0;
    while (x) {
        x /= 2;
        ++res;
    }
    return res - 1;
}
int get_all(pii x) {
    return x.first + x.second;
}
bool solve(){
    sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += a[i];
    }
    if (sum % n) return false;
    average = sum / n;
    for (int i = 1; i <= n; ++i) {
        ll cur = a[i] - average;
        if (!cur) continue;
        int sgn = (cur >= 0);
        cur = std::abs(cur);
        int last = modify(lowbit(cur));
        cur += lowbit(cur);
        if (lowbit(cur) == cur) {
            if (modify(cur) == last + 1) {
                count[sgn][last].second += 1; 
            } else {
                count[sgn][modify(lowbit(cur))].first += 1;
                count[sgn ^ 1][last].first += 1;
            }
        } else {
            return false;
        }
    }
    for (int i = 30; i >= 0; --i) {
        int left = get_all(count[0][i]);
        int right = get_all(count[1][i]);
        int remain = abs(left - right);
        if (!remain) continue;
        int sgn = (left - right > 0);
        if (!i || count[sgn][i - 1].second < remain) return false;
        count[sgn][i - 1].second -= remain;
        count[sgn ^ 1][i - 1].first += remain;
    }
    return true;
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
        memset(count, 0, sizeof(count));
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
        }
        if (solve()) std::cout << "YES\n";
        else std::cout << "NO\n";
    }

    return 0;
}
