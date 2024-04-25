#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,k,a[maxn],mn,mx,ans;
int main(){
	int T=1;scanf("%d",&T);
	while(T--){	
		mn=1e9,mx=0,ans=1e9;
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			mn=min(mn,a[i]);
			mx=max(mx,a[i]);
		}
		for(int i=0;i<=mn;i++){
			int flag=0,res=0;
			for(int j=1;j<=n;j++){
				int temp;
				if(!i)temp=k;
				else if(i==1)temp=min(k,a[j]);
				else temp=a[j]/i;
				temp=min(temp,k);
				if(a[j]/temp==i)flag=1;
				res=max(res,a[j]/temp);
			}
			if(flag){
				ans=min(res-i,ans);
			}
		}
		printf("%d\n",ans);
	}


	return 0;
}