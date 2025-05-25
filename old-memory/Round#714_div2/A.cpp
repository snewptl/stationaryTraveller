#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+5;
int a[maxn];
int main(){
	int T;scanf("%d",&T);
	while(T--){
		int n,k;
		scanf("%d%d",&n,&k);
		if((n-1)/2<k)printf("-1\n");
		else {
			a[1]=1;
			for(int i=1;i<=k;i++)a[2*i+1]=2*i;
			for(int i=1;i<=k;i++)a[i*2]=2*i+1;
			for(int i=2*k+2;i<=n;i++)a[i]=i;
			for(int i=1;i<=n;i++)printf("%d ",a[i]);
			printf("\n");
		}
			
	}


	return 0;
}