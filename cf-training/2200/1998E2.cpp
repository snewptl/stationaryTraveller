#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
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
int n, x;
int a[maxn];
std::vector<int> collection[maxn];
std::set<int, std::greater<int>> available_left;
pli go_left[maxn];
ll sum[maxn];
void solve() {
    for (int i = 1; i <= n; ++i) {
        sum[i] = sum[i - 1] + a[i];
        collection[i].clear();
    }
    available_left.clear();
    for (int i = 1; i <= n; ++i) {
        go_left[i] = {a[i], i};
        while (go_left[i].second > 1 && go_left[i].first >= a[go_left[i].second - 1]) {
            go_left[i].first += go_left[go_left[i].second - 1].first;
            go_left[i].second = go_left[go_left[i].second - 1].second;
        }
    }
    for (int i = 1; i <= n; ++i) {
        std::vector<int> need_pop;
        for (auto it : available_left) {
            ll cur = sum[i - 1] - sum[it - 1]; 
            if (cur < a[i]) {
                need_pop.push_back(it);
            } else {
                cur += a[i];
                if (it != *(--available_left.end()) && cur >= a[it - 1]) {
                    int now = it;
                    int pre = *available_left.upper_bound(now);
                    for (auto it : collection[now]) {
                        collection[pre].push_back(it);
                    }  
                    collection[now].clear();
                    need_pop.push_back(it);
                }
            }
        }
        for (auto it : need_pop) {
            collection[it].clear();
            available_left.erase(it);
        }
        available_left.insert(go_left[i].second);
        collection[go_left[i].second].push_back(i);
        std::cout << collection[1].size() << '\n';
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
        std::cin >> n >> x;
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
        }
        solve();
    }

    return 0;
}