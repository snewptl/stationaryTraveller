[7/6/2025, 11:10:37 AM] 对于 C++ 源文件,cppStandard 已根据编译器参数和查询 compilerPath 从"gnu++23"更改为"gnu++20":"/usr/bin/clang"
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
int vis[maxn], pre[maxn], nxt[maxn];
int a[maxn];
int b[maxn];
std::map<int, int>mp;
std::vector<std::set<int>> vec;
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
        mp.clear();
        for (int i = 1; i <= n; ++i) {
            vis[i] = 0;
            pre[i] = i - 1;
            nxt[i] = i + 1; 
        }
        vis[0] = 1;
        vis[n + 1] = 1;
        pre[n + 1] = n;
        nxt[0] = 1;
        std::set<pii, std::greater<pii>> s;
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
            b[i] = a[i];
        }
        int ans = 0;
        std::sort(b + 1, b + n + 1);
        vec.clear();
        vec.resize(n + 1);
        for (int i = 1; i <= n; ++i) mp[b[i]] = i;
        for (int i = 1; i <= n; ++i) {
            vec[mp[a[i]]].insert(i);
        }
        for (int i = n; i >= 1; --i) {
            if (s.empty() || s.begin()->first != b[i]) {
                ++ans;
                s.insert({b[i], *vec[mp[b[i]]].begin()});
                vis[*vec[mp[b[i]]].begin()] = 1;
                vec[mp[b[i]]].erase(vec[mp[b[i]]].begin());
            }
            int pos = s.begin()->second;
            s.erase(s.begin());
            if (!vis[pre[pos]]) s.insert({a[pre[pos]], pre[pos]}), vis[pre[pos]] = 1;
            if (!vis[nxt[pos]]) s.insert({a[nxt[pos]], nxt[pos]}), vis[nxt[pos]] = 1;
            nxt[pre[pos]] = nxt[pos];
            pre[nxt[pos]] = pre[pos];
        }
        std::cout << ans << '\n';
    }

    return 0;
}

// 1 : 30 - 