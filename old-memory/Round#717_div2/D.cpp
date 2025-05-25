#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n,q;
int a[maxn];
int r[maxn][50],h[maxn];
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
int sum,le,ri;
void find(){
	for(int i=25;i>=0;i--){
		if(r[le][i]<=ri){
			sum+=(1<<i);
			le=r[le][i];
		}
	}
	sum++;
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<maxn;i++)h[i]=n+1;
	for(int i=0;i<=30;i++)r[n+1][i]=n+1;
	for(int i=n;i>=1;i--){
		int mn=n+1;
		for(int j=2;j*j<=a[i];j++){
			if(a[i]%j==0){
				mn=min(mn,h[j]);
				h[j]=i;
				while(a[i]%j==0){
					a[i]/=j;
				}
			}
		}
		if(a[i]!=1)mn=min(mn,h[a[i]]),h[a[i]]=i;
		r[i][0]=min(mn,r[i+1][0]);
	}
	for(int i=1;i<=30;i++){
		for(int j=1;j<=n;j++){
			r[j][i]=r[r[j][i-1]][i-1];
		}
	}
	while(q--){
		sum=0;
		scanf("%d%d",&le,&ri);
		find();
		printf("%d\n",sum);
	}

    return 0;
}