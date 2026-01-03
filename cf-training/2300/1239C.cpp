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
int n;
ll p;
ll t[maxn];
ll ans[maxn];
int main() {
    #ifndef ONLINE_JUDGE
    freopen("0_input.txt", "r", stdin);
    // freopen("0_output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    // std::cin >> T;
    while (T--) {  
        std::cin >> n >> p;
        std::vector<pli> vec;
        for (int i = 1; i <= n; ++i) {
            std::cin >> t[i];
            vec.push_back({t[i], i});
        }
        std::sort(all(vec));
        std::queue<int> tank;
        std::set<int> s, ready;
        ll cur = -1;
        int last = n + 1;
        for (auto [time, id] : vec) {
            while (cur < time) {
                if (!tank.empty()) {
                    int out = tank.front(); tank.pop();
                    s.erase(out);
                    cur += p;
                    ans[out] = cur;
                    last = out;
                }
                if (tank.empty() && cur < time && !ready.empty()) {
                    int out = *ready.begin(); 
                    s.insert(out);
                    tank.push(out);
                    ready.erase(out);
                }
                if (tank.empty()) break;
            }
            if (cur < time) {
                cur = time + p;
                ans[id] = cur;
                last = id;
            } else {
                if (last >= id && s.lower_bound(id) == s.begin() && ready.lower_bound(id) == ready.begin()) {
                    s.insert(id);
                    tank.push(id);
                }
                else {
                    ready.insert(id);
                }
            }
        }
        while (!ready.empty()) {
            int out = *ready.begin(); 
            s.insert(out);
            tank.push(out);
            ready.erase(out);
        }
        while (!tank.empty()) {
            int out = tank.front(); tank.pop();
            s.erase(out);
            cur += p;
            ans[out] = cur;
        }
        
        for (int i = 1; i <= n; ++i) {
            std::cout << ans[i] << ' ';
        }
        std::cout << '\n';
        
    }

    return 0;
}
/// 11 : 34