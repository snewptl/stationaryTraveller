#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int l,r,tmp,mx,bi[50],mi[50];
int u[1005],v[1005],w[1005],cnt;
void init(){
	mi[0]=1;int p=r;
	for(int i=1;i<=20;i++)mi[i]=mi[i-1]*2;	
	while(p){
		if(mi[tmp]&p)bi[tmp]=1,p-=mi[tmp],mx=max(mx,tmp);
		tmp++;
	}
}
int main(){
	scanf("%d%d",&l,&r);
    r-=l;init();
	for(int i=2;i<=mx+2;i++){
		for(int j=2;j<i;j++)
			u[++cnt]=j,v[cnt]=i,w[cnt]=mi[j-2];
		u[++cnt]=1,v[cnt]=i,w[cnt]=1;
	}
	for(int i=0;i<=20;i++){
		if(bi[i]){
			r-=mi[i];
			u[++cnt]=i+2,v[cnt]=mx+3,w[cnt]=l+r;
		}
	}
	u[++cnt]=1,v[cnt]=mx+3,w[cnt]=l;
	printf("YES\n");
	printf("%d %d\n",mx+3,cnt);
	for(int i=1;i<=cnt;i++){
		printf("%d %d %d\n",u[i],v[i],w[i]);
	}
    return 0;
}