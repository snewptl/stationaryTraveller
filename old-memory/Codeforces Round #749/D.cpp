#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=1e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,k;
int a[105];
int ans[105];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)a[i]=1;
	for(int i=n-1;i>=1;i--){
		a[n]=i+1;
		printf("? ");
		for(int j=1;j<=n;j++)printf("%d ",a[j]);
		printf("\n");
		fflush(stdout);
		scanf("%d",&k);
		if(k){
			ans[n]=n-i;
			break;
		}
	}
	if(!k)ans[n]=n;
	for(int i=1;i<ans[n];i++){
		printf("? ");
		for(int j=1;j<n;j++)printf("%d ",i+1);
		printf("1");
		printf("\n");
		fflush(stdout);
		scanf("%d",&k);
		ans[k]=ans[n]-i;
	}
	for(int i=1;i<=n-ans[n];i++){
		printf("? ");
		for(int j=1;j<n;j++)printf("1 ");
		printf("%d",i+1);
		printf("\n");
		fflush(stdout);		
		scanf("%d",&k);
		ans[k]=ans[n]+i;
	}
	printf("! ");
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);
	printf("\n");
	fflush(stdout);	
	return 0;
}