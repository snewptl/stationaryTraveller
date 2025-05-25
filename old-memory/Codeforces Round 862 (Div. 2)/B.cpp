#include<bits/stdc++.h>
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
string s;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;cin>>T;
    while(T--){
        int n;
        cin>>n>>s;
        char mn='z';
        int pos;
        for(int i=0;i<s.size();i++){
            if(mn>=s[i])pos=i;
            mn=min(mn,s[i]);
        }
        cout<<mn;
        for(int i=0;i<s.size();i++){
            if(i==pos)continue;
            cout<<s[i];
        }
        cout<<'\n';
    }

    return 0;
}