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
const int maxn=3e5+5;
const double eps=1e-10;
const int inf=1e9;
int n,a[maxn];
vector<int>pos,neg;
int mn,mx;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;cin>>T;
    while(T--){
        cin>>n;
        mx=-inf,mn=inf;
        pos.clear();
        neg.clear();
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n;i++){
            if(a[i]>0)mx=max(mx,a[i]),pos.push_back(a[i]);
            else mn=min(mn,a[i]),neg.push_back(-a[i]);
        }
        if(mx==0||mn==0)cout<<"NO\n";
        else {
            sort(all(neg));
            sort(all(pos));
            cout<<"YES\n";
            cout<<pos.back()<<' ';
            ll cur=pos.back();
            pos.pop_back();
            while(!pos.empty()||!neg.empty()){
                if(!pos.empty()&&cur+pos.back()<=mx){
                    cout<<pos.back()<<' ';
                    cur+=pos.back();
                    pos.pop_back();
                    continue;
                } 
                if(!neg.empty()&&cur-neg.back()>mn){
                    cout<<-neg.back()<<' ';
                    cur-=neg.back();
                    neg.pop_back();
                    continue;
                }
            }
            cout<<'\n';
        }
    }

    return 0;
}