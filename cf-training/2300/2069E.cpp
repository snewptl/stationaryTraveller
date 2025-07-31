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
const int maxn = 5e5 + 5;
const ll mod = 998244353;
std::string s;
int a, b, ab, ba, n;
std::vector<int> vec[4];
bool solve() {
    int i = 1;
    char start = s[0], cur = s[0];
    int start_pos = 0;
    s.push_back('#');
    while (i <= n) {
        while (i < n && cur != s[i]) {
            cur = s[i++];
        }
        vec[(start - 'A') * 2 + cur - 'A'].push_back(i - start_pos);
        start_pos = i;
        start = cur = s[i];
        ++i;
    }
    std::sort(all(vec[1]));
    for (auto &it : vec[1]) {
        assert(it % 2 == 0);
        if (it / 2 <= ab) ab -= it / 2;
        else {
            it -= ab * 2;
            ab = 0;
            a -= 1;
            b -= 1;
            it -= 2;
            int temp = std::min(it, ba * 2);
            ba -= temp / 2;
            it -= temp;
            a -= it / 2;
            b -= it / 2;
        }
    }
    std::sort(all(vec[2]));
    for (auto &it : vec[2]) {
        assert(it % 2 == 0);
        if (it / 2 <= ba) ba -= it / 2;
        else {
            it -= ba * 2;
            ba = 0;
            a -= 1;
            b -= 1;
            it -= 2;
            int temp = std::min(it, ab * 2);
            ab -= temp / 2;
            it -= temp;
            a -= it / 2;
            b -= it / 2;
        }
    }
    for (int i = 0; i < 4; ++i) {
        if (i == 1 || i == 2) continue;
        for (auto &it : vec[i]) {
            assert(it % 2);
            int temp = std::min(it / 2, ab);
            it -= temp * 2;
            ab -= temp;
            temp = std::min(it / 2, ba);
            it -= temp * 2;
            ba -= temp;
            a -= it / 2;
            b -= it / 2;
            if (i == 0) a -= 1;
            else b -= 1;
        }
    }
    if (a < 0 || b < 0 || ab < 0 || ba < 0) return false;
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
        std::cin >> s >> a >> b >> ab >> ba;
        n = s.size();
        for (int i = 0; i < 4; ++i) vec[i].clear();
        std::cout << (solve() ? "YES\n" : "NO\n");
    }

    return 0;
}
// B - A - B - A - B - A
// 17 : 54 - 18 : 15 - 21min 
// 11 : 02 - 11 : 46 - 44min