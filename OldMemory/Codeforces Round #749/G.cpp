#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=1e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n;
int a[105];
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		int sum=0;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]),sum+=a[i];
		int flag=0;
		for(int i=2;i*i<=sum;i++){
			if(sum%i==0)flag=1;
		}
		int sz=n;
		if(!flag){
			for(int i=1;i<=n;i++){
				if(a[i]%2){a[i]=0;break;}
			}
			sz--;
		}
		printf("%d\n",sz);
		for(int i=1;i<=n;i++){
			if(a[i])printf("%d ",i);
		}
		printf("\n");

	}


	return 0;
}