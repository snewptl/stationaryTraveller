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
struct Para{
    ll a,b,c;
    pll seg;
    void init(){
        ll temp=a*c;
        if(temp<=0)seg={0,-1};
        else {
            ll cur=sqrt(temp);
            while(cur*cur<temp)cur++;
            while(cur*cur>=temp)cur--;
            seg.first=-cur*2+b;
            seg.second=cur*2+b;
            while((seg.first-1-b)*(seg.first-1-b)<4*temp)seg.first--;
            while((seg.second+1-b)*(seg.second+1-b)<4*temp)seg.second++; 
        }
    }
}para[maxn];
ll line[maxn];
int n,m;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;cin>>T;
    while(T--){
        cin>>n>>m;
        for(int i=1;i<=n;i++)cin>>line[i];
        sort(line+1,line+n+1);
        for(int i=1;i<=m;i++){
            int a,b,c;
            cin>>a>>b>>c;
            para[i].a=a,para[i].b=b,para[i].c=c;
            para[i].init();
        }
        for(int i=1;i<=m;i++){
            auto s=para[i].seg;
            // cout<<para[i].a<<" "<<para[i].b<<" "<<para[i].c<<'\n';
            if(s.first>s.second)cout<<"NO\n";
            else {
                auto it=lower_bound(line+1,line+n+1,s.first);
                if(it==line+n+1)cout<<"NO\n";
                else {
                    if(*it<=s.second){
                        cout<<"YES\n";
                        cout<<*it<<'\n';
                    }
                    else cout<<"NO\n";
                }
            }
            // cout<<s.first<<" $$ "<<s.second<<'\n';
        }
        if(T)cout<<"\n";
    }

    return 0;
}
/*
1
1 1
12152
9617 -15953 20535
*/