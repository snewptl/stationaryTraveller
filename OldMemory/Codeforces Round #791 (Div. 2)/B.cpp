#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,q,a[maxn],lst[maxn];
ll sum;
int main(){
	int T=1;//scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&q);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]),sum+=a[i];
		pii sgn={-1,0};
		for(int i=1;i<=q;i++){
			int opt,x,pos;
			scanf("%d",&opt);
			if(opt==1){
				scanf("%d%d",&pos,&x);
				if(lst[pos]<=sgn.first)a[pos]=sgn.second;
				sum-=a[pos];
				sum+=x;
				lst[pos]=i;
				a[pos]=x;
			}
			else {
				scanf("%d",&x);
				sgn={i,x};
				sum=1ll*x*n;
			}
			printf("%lld\n",sum);
		}
	}


	return 0;
}