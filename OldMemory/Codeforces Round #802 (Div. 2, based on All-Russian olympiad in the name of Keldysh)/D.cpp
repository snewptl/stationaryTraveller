#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,q,a[maxn];
ll ful[maxn],tim[maxn],pre[maxn];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		pre[i]=pre[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		ll temp=a[i]-(ful[i-1]*(i-1)-pre[i-1])-ful[i-1];
		ful[i]=ful[i-1];
		if(temp>0){
			ful[i]+=(temp-1)/i+1;
		}

		temp=ful[i]*i-pre[i];
		ll res=pre[n]-pre[i]-temp;
		tim[i]=ful[i];
		if(res>0){
			tim[i]+=(res-1)/i+1;
		}
	}
	scanf("%d",&q);
	while(q--){
		int x;
		scanf("%d",&x);
		int l=1,r=n,res=n+1;
		while(l<=r){
			int mid=l+r>>1;
			if(tim[mid]>x)l=mid+1;
			else r=mid-1,res=min(res,mid);
		}
		if(res!=n+1)printf("%d\n",res);
		else printf("-1\n");
	}


	return 0;
}