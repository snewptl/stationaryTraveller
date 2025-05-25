#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int n,x;
ll MX=1,MN;
ll cMX=1,cMN;
int le,ri;
int a[maxn];
int b[maxn];
ll ans;
void dfs(int l,int r){
	if(l==r)return;
	int mid=l+r>>1;
	dfs(l,mid);dfs(mid+1,r);
	int le=l,ri=mid+1,p=l;
	while(le<=mid&&ri<=r){
		if(a[le]<=a[ri]){
			b[p++]=a[le];le++;
			if(ri!=mid+1&&a[le-1]>a[ri-1]){
				MX=max(MX,1LL*a[ri-1]);
				MN=min(MN,1LL*a[le-1]);
			}
		}
		else {
			b[p++]=a[ri];ri++;
		}
	}
	while(le<=mid){
		b[p++]=a[le];le++;
		if(a[le-1]>a[ri-1]){
			MN=min(MN,1LL*a[le-1]);
			MX=max(MX,1LL*a[ri-1]);			
		}
	}
	while(ri<=r){
		b[p++]=a[ri];ri++;
	}
	for(int i=l;i<=r;i++)a[i]=b[i];
}
int main(){
    scanf("%d%d",&n,&x);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	ans=1LL*n*(n+1)/2;
	MN=x;cMN=x;
	dfs(1,n);
	MN++,MX--;
	printf("%lld %lld\n",MN,MX);
	printf("%lld\n",ans-(MX?(1+MX)*MX/2:0)-(MN!=x+1?(x-MN+2)*(x-MN+1)/2:0)+(MN<=MX?(MX-MN+2)*(MX-MN+1)/2:0));
    return 0;
}