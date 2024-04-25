/*
1 0 0 0 0  
0 9 9 9 9
*/
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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;cin>>T;
    while(T--){
        string s, t;
        cin >> s >> t;
        reverse(all(s));
        int len = t.size() - s.size();
        for (int i = 0; i < len; i++) s.push_back('0');
        reverse(all(s));
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            ans += t[i] - s[i];
            if (s[i] != t[i]) {
                ans += (s.size() - i - 1) * 9;
                break;
            }

        }
        cout << ans << '\n';
    }

    return 0;
}