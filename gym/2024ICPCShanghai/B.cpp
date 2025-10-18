#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cassert>
#include <queue>
#include <iterator>
#include <array>
#include <numeric>
#include <random>
#include <stack>
#include <unordered_map>

using namespace std;

// #define int long long

// using i64 = int64_t;
using pii = pair<int, int>;
using ll = long long;

constexpr int MAX_N = 3e5 + 7;
// constexpr int N = 4000 * 4000 * 2 + 4000 * 4 + 114514;
// constexpr int INF = 2e9;
// constexpr int MOD = 998244353;
// constexpr int base = 233;
// constexpr int p1 = 1e9 + 7;
// constexpr int p2 = 1e9 + 9;

int fa[MAX_N], siz[MAX_N];

int find(int x) { return fa[x] == x ? fa[x] : find(fa[x]); }

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<set<int>> e(n, set<int>());

    for (int i = 0; i < n; i++) {
        fa[i] = i;
        siz[i] = 1;
    }

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; --u, --v;
        int fu = find(u), fv = find(v);
        if (fu != fv) {
            fa[fu] = fv;
            siz[fv] += siz[fu];
        }
        e[u].insert(v);
        e[v].insert(u);
    }

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i]; --p[i];
    }

    vector<pii> ans;
    stack<int> stk;
    stk.push(p[0]);
    int cnt = 1;

    for (int i = 1; i < n; ) {
        int u = stk.top(), fu = find(u), s = siz[fu];
        int v = p[i], fv = find(v);
        if (fv == fu) { // same component
            if (e[u].size()) {
                if (e[u].find(v) == e[u].end()) {
                    ans.push_back({u, v});
                    // e[u].insert(v);
                    // e[v].insert(u);
                } else {
                    e[u].erase(v);
                    e[v].erase(u);
                }
                i++;
                cnt += 1;
                stk.push(v);
            } else {
                stk.pop();
            }
        } else {
            if (cnt != s) {
                ans.push_back({u, v});
                // e[u].insert(v);
                // e[v].insert(u);
                fa[fu] = fv;
                siz[fv] += s;
                cnt += 1;
                stk.push(v);
            } else {
                while (!stk.empty()) stk.pop();
                cnt = 1;
                stk.push(v);
            }
            i++;
        }
    }

    cout << ans.size() << "\n";
    for (auto [x, y] : ans) {
        cout << x + 1 << " " << y + 1 << "\n";
    }

    return 0;
}

/*


6 6
1 3
1 4
2 3
3 4
3 6
5 6 
1 2 3 4 5 6

7 6
1 3
1 4
2 3
3 4
3 6
5 6 
1 2 3 4 5 6 7
1 2 3 4 5 6

8 8
2 8
3 8
5 6
1 6
6 3
8 7
2 3
4 3 
1 8 7 5 4 2 3 6

6 5
1 2
1 3
4 5
5 6
4 6
1 2 4 3 5 6

5 2
1 2
3 4
1 5 2 3 4

*/