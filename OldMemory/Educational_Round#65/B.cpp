#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int vis[2000];
int x[2000],y[2000];
int k[6]={4,8,15,16,23,42};
int ans[7];
int main(){
	for(int i=0;i<6;i++){
		for(int j=i+1;j<6;j++){
			x[k[i]*k[j]]=i;y[k[i]*k[j]]=j;
		}
	}
	int a,b,c,d;
	printf("? 1 3\n");
	fflush(stdout);
	scanf("%d",&a);
	printf("? 2 4\n");
	fflush(stdout);
	scanf("%d",&b);
	printf("? 3 5\n");
	fflush(stdout);
	scanf("%d",&c);	
	printf("? 1 2\n");
	fflush(stdout);
	scanf("%d",&d);
	if(x[a]==x[d]){
		ans[1]=k[x[a]];
	}
	else if(x[a]==y[d]){
		ans[1]=k[x[a]];
	}
	else ans[1]=k[y[a]];
	ans[2]=d/ans[1];
	ans[3]=a/ans[1];
	ans[5]=c/ans[3];
	ans[4]=b/ans[2];
	for(int i=1;i<=5;i++)vis[ans[i]]=1;
	for(int i=0;i<6;i++)if(!vis[k[i]])ans[6]=k[i];
	printf("!");
	for(int i=1;i<=6;i++){
		printf(" %d",ans[i]);
	}
	printf("\n");
	fflush(stdout);

    return 0;
}