#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,a[maxn];
vector<pii>vec;
ll sum[maxn],xr[maxn];
int q;
void solve(int l,int r){
    ll res=0;
    int len=1;
    pii ans={l,l};
    for(int idx=1;idx<vec.size();idx++){
        int i=vec[idx].second;
        ll temp=sum[i]-sum[l-1]-(xr[i]^xr[l-1]);
        if(res<=temp){
            if(res<temp)res=temp,len=i-vec[0].second+1,ans={vec[0].second,i};
            // ans={l,i};
            ll cur=0;
            int j=vec[0].second;
            for(int ndx=0;ndx<min(idx,30);ndx++){
                j=vec[ndx].second;
                if(((cur^a[j])==(cur+a[j]))&&((cur^a[j]^xr[i]^xr[l-1])==((xr[i]^xr[l-1])-(cur^a[j]))))cur^=a[j];
                else break;
            }
            if(len>i-j+1)len=i-j+1,ans={j,i};
        }
    }
    printf("%d %d\n",ans.first,ans.second);
}
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
        vec.clear();
        scanf("%d%d",&n,&q);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            if(a[i])vec.push_back({a[i],i});
            sum[i]=sum[i-1]+a[i];
            xr[i]=(xr[i-1]^a[i]);
        }
        for(int cs=1;cs<=q;cs++){
            int l,r;
            scanf("%d%d",&l,&r);
            solve(l,r);
        }

	}


	return 0;
}