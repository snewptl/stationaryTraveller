#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef pair<ll,ll> pll;
typedef pair<int,ll> pil;
typedef double db;
typedef long double ldb;
const ll mod=998244353;
const int maxn=2e5+5;
const double eps=1e-10;
int n,k;
ll x;
ll a[maxn],pre[maxn];
ll ans;
vector<pil>vec;
void solvep(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=min(i,2*k);j++){
            ans=max(ans,(j>=k?k*2-j:j)*x+pre[i]-pre[i-j]);
        }
    }
    vec.clear();
    vec.push_back({0,0});
    for(int i=1;i<=n;i++){
        ll temp=-x*i+pre[i];
        for(int j=vec.size()-1;j>=max((int)vec.size()-50,0);j--)
            if(i-vec[j].first>=2*k){
                ans=max(ans,temp+vec[j].second+2*k*x);
                break;
            }
        if(-temp>vec.back().second)vec.push_back({i,-temp});
    }
}
void solven(){
    for(int i=1;i<=k;i++){
        for(int j=max(i,n-k+1);j<=n;j++){
            int out=i-1+n-j;
            if(out>k)continue;
            ans=max(ans,(pre[j]-pre[i-1])-x*(n-k)+x*(k-out));
        }
    }
    vec.clear();
    vec.push_back({0,0});
    for(int i=1;i<=n;i++){
        ll temp=-x*i+pre[i];
        for(int j=max((int)vec.size()-50,0);j<vec.size();j++)
            if(i-vec[j].first<=n-k){
                ans=max(ans,temp+vec[j].second);
                break;
            }
        while(!vec.empty()&&-temp>=vec.back().second)vec.pop_back();
        vec.push_back({i,-temp});
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;cin>>T;
    while(T--){
        cin>>n>>k>>x;
        ans=0;
        for(int i=1;i<=n;i++)
            cin>>a[i],pre[i]=pre[i-1]+a[i];
        if(x>=0)solvep();
        else solven();
        cout<<ans<<'\n';
    }

    return 0;
}