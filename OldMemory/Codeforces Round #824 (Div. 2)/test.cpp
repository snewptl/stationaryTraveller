#include <bits/stdc++.h>
using std::cin;
using std::cout;

using ll = long long;

ll INF = ll(1e18) + 5;

ll Mul(ll a,ll b) {
    __int128_t x = a;
    __int128_t y = b;
    return x * y >= INF ? INF : x * y;
}
ll Add(ll a,ll b) {
    return std::min(a + b,INF);
}

ll p2(int y) {
    if (y >= 60) {
        return INF;
    } else {
        return 1LL<<y;
    }
}

int n;
ll count(int num,bool s0,bool s1) {
    if (num <= (n + 1) / 2) {
        int free = (n + 1) / 2 - num;
        ll c0 = (n / 2) / 2;
        ll c1 = n / 2 - (n / 2) / 2;
        ll x = Mul(p2(free),Add(p2(c0),p2(c1)) - 1);
        return x;
    }
    int remain = n - num;
    int c0,c1;
    if (num % 2 == 0) {
        c0 = remain - remain / 2;
        c1 = remain / 2;
    } else {
        c1 = remain - remain / 2;
        c0 = remain / 2;
    }
    if (s0 && s1) {
        return Add(p2(c0),p2(c1)) - 1;
    } else if (s0 || s1) {
        return 1;
    } else {
        return 0;
    }
}

using str = std::string;
void solve() {
    ll k;
    cin>>n>>k;
    k--;
    bool val[2] = {true,true};
    str ans;

    std::vector<int> mp(n);
    std::vector<int> v[2];
    for (int i = 0;i < n;i++) {
        v[i % 2].push_back(i);
    }

    for (int i = 0;i < 2;i++) {
        int len = (int) v[i].size();
        for (int j = 0;j < len;j++) {
            mp[v[i][j]] = v[i][len - 1 - j];
        }
    }
    for (int i = 0;i < n;i++) {
        //assert(val[0] || val[1]);
        bool nxt[2] = {val[0],val[1]};
        if (i >= (n + 1) / 2) {
            if (ans[mp[i]] != '0') {
                nxt[i % 2] = false;
            }
        }
        ll tmp = count(i + 1,nxt[0],nxt[1]);
        if (k < tmp) {
            ans.push_back('0');
            val[0] = nxt[0],val[1] = nxt[1];
            continue;
        }
        ans.push_back('1');
        k -= tmp;
        if (i >= (n + 1) / 2) {
            if (ans[mp[i]] != '1') {
                val[i % 2] = false;
            }
        }
        //cout<<k<<'\n';
    }
    if (k != 0) {
        cout<<"NOT FOUND!\n";
        return;
    }
    //assert(k == 0);
    cout<<ans<<'\n';
}

int main() {
    std::ios::sync_with_stdio(0);
    cin.tie(0);

#ifdef LOCAL
    freopen("input.txt","r",stdin);
#endif

    int t;
    cin>>t;
    for (int i = 1;i <= t;i++) {
        cout<<"Case #"<<i<<": ";
        solve();
    }

    return 0;
}
