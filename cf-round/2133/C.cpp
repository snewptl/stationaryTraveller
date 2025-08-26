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
int ask(int x, std::vector<int>& vec) {
    std::cout << "? " << x << ' ';
    std::cout << vec.size() << ' ';
    for (auto it : vec) std::cout << it << ' ';
    std::cout << std::endl;
    int res;
    std::cin >> res;
    return res;
}
std::vector<std::vector<int>> dis;
int main() {
    #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> n;
        dis.clear();
        dis.resize(n + 1);
        std::vector<int> all_node;
        for (int i = 1; i <= n; ++i) {
            all_node.push_back(i);
        } 
        int mx = 0;
        for (int i = 1; i <= n; ++i) {
            int d = ask(i, all_node);
            dis[d].push_back(i);
            mx = std::max(mx, d);
        }
        std::vector<int> ans;
        int cur = dis[mx].back();
        ans.push_back(cur);
        for (int i = mx - 1; i >= 1; --i) {
            for (auto it : dis[i]) {
                std::vector<int> temp;
                temp.push_back(cur);
                temp.push_back(it);
                int res = ask(cur, temp);
                if (res == 2) {
                    cur = it;
                    ans.push_back(cur);
                    break;
                }
            }
        }
        std::cout << "! " << ans.size() << " ";
        for (auto it : ans) std::cout << it << ' ';
        std::cout << std::endl;
    }

    return 0;
}
