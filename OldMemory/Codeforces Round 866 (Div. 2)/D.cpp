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
multiset<pll,greater<pll>>s[2];
int n;
pll a[maxn];
vector<pll>res;
ll sum;
bool check(ll h,ll w,int flag,ll sum){
    if(s[0].empty())return true;
    if(flag==0){
        if(s[0].begin()->first!=h)return false;
        while(!s[0].empty()&&s[0].begin()->first==h){
            auto temp=*s[0].begin();
            s[0].erase(s[0].begin());
            swap(temp.first,temp.second);
            auto it=s[1].lower_bound(temp);
            s[1].erase(it);
            sum-=1ll*temp.first*temp.second;
        }
        return sum%h==0&&check(h,sum/h,flag^1,sum);
    }
    else {
        if(s[1].begin()->first!=w)return false;
        while(!s[1].empty()&&s[1].begin()->first==w){
            auto temp=*s[1].begin();
            s[1].erase(s[1].begin());
            swap(temp.first,temp.second);
            auto it=s[0].lower_bound(temp);
            s[0].erase(it);
            sum-=1ll*temp.first*temp.second;
        }
        return sum%w==0&&check(sum/w,w,flag^1,sum);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;cin>>T;
    while(T--){
        sum=0;
        s[0].clear();s[1].clear();
        res.clear();
        cin>>n;
        for(int i=1;i<=n;i++){
            ll x,y;cin>>x>>y;
            a[i]={x,y};
            s[0].insert({x,y});
            s[1].insert({y,x});
            sum+=1ll*x*y;
        }
        ll temp=s[0].begin()->first;
        if(sum%temp==0&&check(temp,sum/temp,0,sum))res.push_back({temp,sum/temp});

        s[0].clear();s[1].clear();
        for(int i=1;i<=n;i++){
            s[0].insert(a[i]);
            s[1].insert({a[i].second,a[i].first});
        }
        temp=s[1].begin()->first;
        if(sum%temp==0&&check(sum/temp,temp,1,sum))res.push_back({sum/temp,temp});
        
        sort(all(res));
        res.resize(unique(all(res))-res.begin());
        cout<<res.size()<<'\n';
        for(auto it:res)cout<<it.first<<" "<<it.second<<'\n';
    }

    return 0;
}