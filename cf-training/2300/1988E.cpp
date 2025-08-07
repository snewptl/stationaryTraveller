#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const int N = 5e5 + 10;
int a[N], pos[N];
ll ans[N];
 
void update(int l, int r, ll val) {
    if (l <= r) {
        ans[l] += val;
        ans[r + 1] -= val;
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
 
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
 
        for (int i = 1; i <= n; i++) {
            ans[i] = 0;
            pos[a[i]] = i;
        }
 
        set<int> s;
        s.insert(0);
        s.insert(n + 1);
        for (int val = 1; val <= n; val++) {
            int i = pos[val];
            auto rig_it = s.lower_bound(i);
            int rig = *rig_it;
            auto lef_it = rig_it;
            lef_it--;
            int lef = *lef_it;
            if (lef >= 2) { // delete [1, lef - 1]
                update(1, lef - 1, 1ll * (i - lef) * (rig - i) * a[i]);
            }
            if (rig <= n - 1) { // delete [rig + 1, n]
                update(rig + 1, n, 1ll * (i - lef) * (rig - i) * a[i]);
            }
            { // delete [lef + 1, i - 1]
                update(lef + 1, i - 1, 1ll * (i - lef - 1) * (rig - i) * a[i]);
            }
            { // delete [i + 1, rig - 1]
                update(i + 1, rig - 1, 1ll * (i - lef) * (rig - i - 1) * a[i]);
            }
            if (lef >= 1) { // delete [lef]
                lef_it--;
                int x = *lef_it;
                update(lef, lef, 1ll * (i - x - 1) * (rig - i) * a[i]);
            }
            if (rig <= n) { // delete [rig]
                rig_it++;
                int x = *rig_it;
                update(rig, rig, 1ll * (i - lef) * (x - i - 1) * a[i]);
            }
            s.insert(i);
        }
 
        for (int i = 1; i <= n; i++) {
            ans[i] += ans[i - 1];
        }
        for (int i = 1; i <= n; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
 
#ifdef LOCAL
    cout << "\nTime elapsed: " << double(clock()) / CLOCKS_PER_SEC << " s.\n";
#endif
}