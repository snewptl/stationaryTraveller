#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=1e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,a[maxn];
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		ll sum=0;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)sum+=a[i];
		int pos=0;
		for(int i=1;i<=n;i++){
			if(sum!=a[i]){
				pos=i;break;
			}
		}
		if(abs(sum-a[pos])+1ll*abs(a[pos])*(n-1)>1e9){
			for(int i=1;i<=n;i++){
				if(sum!=a[i]&&sum*a[i]>0){
					pos=i;
					break;
				}
			}
		}
		ll res=1ll*(sum-a[pos])*a[pos];
		ll x,y;
		x=res/(sum-a[pos]);
		y=res/a[pos];
		if(y*a[pos]==x*(sum-a[pos]))y=-y;
		for(int i=1;i<=n;i++){
			if(i==pos)printf("%d ",y);
			else printf("%d ",x);
		}
		printf("\n");
	}


	return 0;
}