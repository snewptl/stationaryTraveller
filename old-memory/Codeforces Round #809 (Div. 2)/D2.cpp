#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=1e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,k,a[maxn],mn,mx,ans;
vector<int>vec;
int vis[maxn],top[maxn],mk[maxn];
void init(){
	mn=1e9,mx=0,ans=1e9;
	vec.clear();	
	for(int i=0;i<=1e5;i++)vis[i]=top[i]=mk[i]=0;
}
void update(int rt,int l,int r,int xl,int xr){
	
}
int main(){
	int T=1;scanf("%d",&T);
	while(T--){	
		scanf("%d%d",&n,&k);
		init();
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			mn=min(mn,a[i]);
			mx=max(mx,a[i]);
			vis[a[i]]++;
		}
		for(int i=1;i<=1e5;i++){
			if(!vis[i])continue;
			for(int j=1;j<=k;j=i/(i/j)+1){
				int temp=i/j;
				top[temp]=1;
				if(!temp)break;
			}
		}
		for(int i=0;i<=1e5;i++)if(top[i]&&i>=mx/k)vec.push_back(i);
		for(int i=1;i<=1e5;i++){
			if(!vis[i])continue;
			int cur,pos,pre=-1;
			for(int j=1;j<=k;j=i/(i/j)+1){
				cur=i/j;
				pos=lower_bound(vec.begin(),vec.end(),cur)-vec.begin();
				if(pre!=pos)
					mk[pos]=min(mk[pos],cur);
				pre=pos;
				if(cur==0)break;
			}
		}
		int temp=0;
		for(int i=0;i<vec.size();i++){
			temp=max(temp,mk[i]);
			ans=min(ans,vec[i]-temp);
		}
		printf("%d\n",ans);
	}


	return 0;
}