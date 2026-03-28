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
int r, g, b;
std::vector<std::pair<int, char>> vec;
void output(int x, int y) {
    std::cout << vec[x].second << vec[y].second;
    vec[x].first -= 1;
    vec[y].first -= 1;
}
void output(int x, int y, int z) {
    std::cout << vec[x].second << vec[y].second << vec[z].second;
    vec[x].first -= 1;
    vec[y].first -= 1;
    vec[z].first -= 1;
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("0_input.txt", "r", stdin);
    // freopen("0_output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    std::cin >> T;
    while (T--) {
        vec.clear();
        std::cin >> r >> g >> b;
        vec.push_back({r, 'R'});
        vec.push_back({g, 'G'});
        vec.push_back({b, 'B'});
        std::sort(all(vec));
        std::reverse(all(vec));
        while (vec[1].first != vec[2].first) {
            output(0, 1);
        }
        int flag = 0;
        while (vec[0].first != vec[1].first && vec[1].first) {
            output(0, 1);
            output(0, 2);
            flag = 1;
        }
        if (!flag) {
            std::swap(vec[1], vec[2]);
        }
        while (vec[2].first) {
            output(0, 2, 1);
            if (vec[2].first) {
                output(2, 1, 0);
            }
            vec[3] = vec[0];
            vec[0] = vec[1];
            vec[1] = vec[2];
            vec[2] = vec[3];
        }
        if (vec[0].first) {
            std::cout << vec[0].second;
        }
        std::cout << '\n';
    }

    return 0;
}
