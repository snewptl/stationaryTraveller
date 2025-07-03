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
int n;
int deg[maxn];
std::vector<pii> vec;
int main() {
    #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n;
    for (int i = 1; i <= n; ++i) std::cin >> deg[i], vec.push_back({deg[i], i});
    sort(all(vec));
    int flag = 1;
    int sz = vec.size();
    while (sz && flag) {
        flag = 0;
        if (vec[0].first == 0) {
            for (int i = 0; i < sz - 1; ++i) vec[i] = {vec[i + 1].first - 1, vec[i + 1].second};
            vec.resize(sz - 1);
            --sz;
            flag = 1;
        } else if (vec[sz - 1].first == sz - 1) {
            vec.resize(sz - 1);
            --sz;
            flag = 1;
        }
    }

    for (int len = sz - 2; len >= 0; --len) {
        for (int i = 0; i < sz; ++i) {
            for (int j = i + 1; j < sz; ++j) {
                if (vec[i].first + len > vec[j].first) continue;
                if (vec[i].first + len < vec[j].first) break;
                std::cout << "? " << vec[j].second << ' ' << vec[i].second << std::endl;
                std::string res;
                std::cin >> res;
                if (res[0] == 'Y') {
                    std::cout << "! " << vec[j].second << ' ' << vec[i].second << std::endl;
                    exit(0);
                }
            }
        }
    }

    std::cout << "! 0 0" << std::endl;

    return 0;
}

// 15 : 55 - 16 : 14