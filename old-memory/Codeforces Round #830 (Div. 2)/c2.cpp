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
int rk[maxn];
int q;
void solve(int l,int r){
    int le=max(rk[l],0);
    int ri=rk[r];
    if(le>ri){
        printf("%d %d\n",l,l);
        return ;
    }
    ll res=0;
    pii ans={l,l};
    int idx=ri;
    int i=vec[idx].second;
    ll temp=sum[i]-sum[l-1]-(xr[i]^xr[l-1]);
    if(temp==0){
        printf("%d %d\n",l,l);
        return ;    
    }
    ll cur=0;
    int j=vec[le].second;
    for(int ndx=le;ndx<min(idx,le+30);ndx++){
        j=vec[ndx].second;
        if(((cur^a[j])==(cur+a[j]))&&((cur^a[j]^xr[i]^xr[l-1])==((xr[i]^xr[l-1])-(cur^a[j]))))cur^=a[j];
        else break;
    }
    ans={j,i};
    cur=0;
    for(int ndx=ri;ndx>min(le,ri-30);ndx--){
        j=vec[ndx].second;
        if(((cur^a[j])==(cur+a[j]))&&((cur^a[j]^xr[i]^xr[ans.first-1])==((xr[i]^xr[ans.first-1])-(cur^a[j]))))cur^=a[j];
        else break;
    }
    ans.second=j;
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
            rk[i]=vec.size()-1;
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