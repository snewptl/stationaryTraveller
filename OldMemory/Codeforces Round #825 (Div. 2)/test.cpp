#include <bits/stdc++.h>

using std::cin;
using std::cout;

using ll = long long;

constexpr int N = 1e5 + 4;
int a[N];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);

#ifdef LOCAL
    freopen("input.txt","r",stdin);
#endif

    int n,k;
    cin>>n>>k;
    ll lc,pc,lm,pm;
    ll t,d;
    cin>>lc>>pc>>lm>>pm;
    cin>>t>>d;
    for (int i = 0;i < n;i++) {
        cin>>a[i];
    }

    std::sort(a,a + n);
    ll INF = 1e9;
    ll free_1 = 0;
    ll free_m = 0,need_m = 0;
    ll free_c = 0,need_c = 0;

    auto add_m = [&] (int x) {
        if (x <= lm) {
            need_m += x < lm - d ? INF : lm - x;
        } else {
            free_m += std::min(d,x - lm);
        }
    };

    auto del_m = [&] (int x) {
        if (x <= lm) {
            need_m -= x < lm - d ? INF : lm - x;
        } else {
            free_m -= std::min(d,x - lm);
        }
    };

    auto add_c = [&] (int x) {
        if (x <= lc) {
            need_c += x < lc - d ? INF : lc - x;
        } else {
            free_c += std::min(d,x - lc);
        }
    };

    for (int i = 0;i < n;i++) {
        add_m(a[i]);
    }

    ll ans = LLONG_MAX;

    int p1 = 0,p2 = n - 1;

    bool full = false;
    for (int x = 0;;x++) {
        ll cur = 0;
        cur = x * pc + (n - k * x) * pm;
        ll tot_free = free_1 + free_m + free_c; 
        bool ok = true;
        if (need_c + need_m > tot_free) {
            ok = false;
        }
        if (ok) ans = std::min(ans,(need_c + need_m) * t + cur);
        if (full) break;
        add_c(a[p2--]);
        for (int j = 0;j < (k - 1);j++) {
            if (p1 > p2) {
                full = true;
                break;
            }
            del_m(a[p1]);
            free_1 += std::min(d,1LL* a[p1] - 1);
            p1++;
        }
    }
    cout<<(ans == LLONG_MAX ? -1 : ans)<<'\n';

    return 0;
}
