#define _USE_MATH_DEFINES
 
#include <math.h>
#include <cmath>
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
 
using namespace std;
 
#define INF (2e9)
 
const int sz = (1 << 18);
 
struct st {
    vector<int> data;
    
    st() {
        data.resize(sz * 2, INF);
    }
    
    void set(int id, int val) {
        data[id + sz] = val;
        for (int i = (id + sz) / 2; i > 0; i /= 2) data[i] = min(data[i * 2], data[i * 2 + 1]);
    }
    
    int get(int l, int r, int ld = 0, int rd = sz, int id = 1) {
        if (l >= rd || r <= ld) return INF;
        if (l <= ld && rd <= r) return data[id];
        return min(get(l, r, ld, (ld + rd) / 2, id * 2), get(l, r, (ld + rd) / 2, rd, id * 2 + 1));
    }
};
 
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q; cin >> n >> q;
    st kk;
    set<int> ods;
    for (int i = 0; i < n; ++i) ods.insert(i);
    while (q--) {
        int t; cin >> t;
        if (t == 0) {
            int l, r, x; cin >> l >> r >> x;
            l--;
            if (x == 0) {
                for (auto cur = ods.lower_bound(l); cur != ods.end() && *cur < r;) {
                    int curval = *cur;
                    ods.erase(cur);
                    cur = ods.upper_bound(curval);
                }
            } else kk.set(l, min(kk.data[sz + l], r));
        } else {
            int id; cin >> id;
            id--;
            if (!ods.count(id)) {
                cout << "NO\n";
                continue;
            }
            int l = 0, r = n;
            if (ods.size()) {
                auto it = ods.lower_bound(id);
                if (it != ods.begin()) l = *prev(it) + 1;
                it++;
                if (it != ods.end()) r = *it;
            }
            cout << (kk.get(l, n) <= r ? "YES" : "N/A") << "\n";
        }
    }
    return 0;
}
 