#include<bits/stdc++.h>
#define all(vec) vec.begin(),vec.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef pair<ll,ll> pll;
typedef double db;
typedef long double ldb;
const ll mod=998244353;
const int maxn=2e5+5;
const double eps=1e-10;
int n;
string s, t;
int check(int flag){
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) res++;
    }
    if (flag == 1 && res == 0) res = 1;
    int rev = res - 1;
    if (rev % 2 != flag) rev++;
    return res + rev;    
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;cin>>T;
    while(T--){
        cin >> n >> s >> t;
        int ans = 0;
        for (int i = 0; i < n/2; ++i) {
            map<int,int> mp;
            mp[s[i]]++, mp[s[n - 1 -i]]++;
            mp[t[i]]++, mp[t[n - 1 -i]]++;
            int mx = 0;
            for(auto it: mp) mx = max(mx, it.second);
            ans += 4 - mx;
        }
        if (n % 2 && s[n / 2] != t[n / 2]) ans++;
        if (ans) ans += ans - 1;
        ans = min(ans, check(0));
        reverse(all(s));
        ans = min(ans, check(1));
        cout << ans << '\n';
    }   

    return 0;
}
/*
left equal
right equal

both equal -> a,b,c,d:3 a,a,c,d:2, a,b,a,c:2
*/