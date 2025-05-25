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
int n,m;
int x[maxn];
vector<int>vec;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;cin>>T;
    while(T--){
        cin>>n>>m;
        for(int i=1;i<=n;i++)cin>>x[i];
        vec.clear();
        for(int i=1;i<=n;i++)if(x[i]>0)vec.push_back(x[i]);
        sort(all(vec));
        vec.resize(unique(all(vec))-vec.begin());
        int le=0,ri=0,pos1=0,posm=0;
        for(auto it:vec){
            if(it==1)pos1++;
            if(it==m)posm++;
        }
        for(int i=1;i<=n;i++){
            if(x[i]==-1)le++;
            if(x[i]==-2)ri++;
        }
        int ans=0;
        ans=max(ans,(int)vec.size()+le);
        ans=max(ans,(int)vec.size()+ri);
        for(int i=0;i<vec.size();i++){
            int l=vec[i]-1-i,r=m-vec[i]-((int)vec.size()-1-i);
            ans=max(ans,min(l,le)+min(r,ri)+(int)vec.size());
        }

        cout<<min(ans,m)<<'\n';
    }

    return 0;
}