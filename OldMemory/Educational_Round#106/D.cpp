#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e7+10;
ll num[maxn];//num[i]为lcm(a,b)==i时(a,b)的种数
int p[maxn],vis[maxn],cnt;
int c,d,x;
void init(){
	num[1]=1;
	for(int i=2;i<maxn-5;i++){
		if(!vis[i])p[cnt++]=i,num[i]=2;
		for(int j=0;j<cnt;j++){
			if(p[j]*i>=maxn-5)break;
			vis[i*p[j]]=1;
			if(i%p[j]==0){
				num[i*p[j]]=num[i];
				break;
			}
			else {
				num[i*p[j]]=num[i]*2;
			}
		}
	}
}
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
int mi[100],tot;
int a[100],temp;
ll ans;
void check(int x){
	if(temp%x)return;
	x=temp/x;
	x+=d;
	if(x%c)return;
	x/=c;
	ans+=num[x];
	
}
void dfs(int dep,int t){
	
	if(dep==tot+1){
		check(t);return;
	}
	int k=1;
	for(int i=0;i<=a[dep];i++){
		
		dfs(dep+1,t*k);k*=mi[dep];
	}
}
int main(){
	init();
    int T;scanf("%d",&T);
    while(T--){
		tot=0,ans=0;
        scanf("%d%d%d",&c,&d,&x);
		int k=gcd(c,d);
		c/=k,d/=k;
		if(x%k){
			printf("0\n");continue;
		}
		x/=k;temp=x;
		for(int i=2;i*i<=x;i++){
			if(x%i==0){
				mi[++tot]=i;
				a[tot]=0;
				while(x%i==0){
					x/=i;a[tot]++;
				}				
			}
		}
		if(x!=1)mi[++tot]=x,a[tot]=1;
		dfs(1,1);
		printf("%lld\n",ans);
    }



    return 0;
}
