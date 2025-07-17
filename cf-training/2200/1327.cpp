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
int n, p[maxn], c[maxn];
int in_circle[maxn], circle_count;
int can[maxn];
std::vector<int> vec;
int len;
void solve(int i) {
    std::vector<int> temp;
    for (int j = 0; j < len; j += i) {
        temp.push_back(j);
    }
    for (int j = 0; j < i; ++j) {
        int flag = 1, last = 0;
        for (auto it : temp) {
            if (last && last != c[vec[it]]) {
                flag = 0;
                break;
            } else {
                last = c[vec[it]];
            }
        }
        if (flag) {
            can[i] = 1;
            break;
        }
        for (auto &it : temp) it += 1, it %= len;
    } 
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
        for (int i = 1; i <= n; ++i) std::cin >> p[i];
        for (int i = 1; i <= n; ++i) std::cin >> c[i];
        circle_count = 0;
        for (int i = 1; i <= n; ++i) {
            in_circle[i] = 0;
            can[i] = 0;
        }
        for (int i = 1; i <= n; ++i) {
            if (in_circle[i]) continue;
            ++circle_count;
            vec.clear();
            int cur = i;
            while (!in_circle[cur]) {
                vec.push_back(cur);
                in_circle[cur] = circle_count;
                cur = p[cur];
            }
            len = vec.size();
            for (int j = 1; j * j <= len; ++j) {
                if (len % j != 0) continue;
                solve(j);
                solve(len / j);
            }
        } 
        for (int i = 1; i <= n; ++i) if (can[i]) {
            std::cout << i << '\n';
            break;
        }
    }

    return 0;
}
// 10 : 50 - 11 : 48
