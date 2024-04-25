#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n;
int a[maxn];
int l[maxn],r[maxn];
int ans,mx,cnt;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	ans=0,mx=0,cnt=0;
	for(int i=1;i<=n;i++)r[i]=i;
	for(int i=1;i<=n;i++)l[i]=i;
	for(int i=n-1;i>=1;i--){
		if(a[i+1]<a[i])r[i]=r[i+1];
		if(r[i]-i+1>mx)mx=r[i]-i+1,cnt=1;
		else if(r[i]-i+1==mx)cnt++;
	}
	for(int i=2;i<=n;i++){
		if(a[i-1]<a[i])l[i]=l[i-1];
		if(i-l[i]+1>mx)mx=i-l[i]+1,cnt=1;
		else if(i-l[i]+1==mx)cnt++;
	}
	for(int i=1;i<=n;i++){
		if(cnt!=2)continue;
		if((r[i]-i+1)%2==0)continue;
		if(r[i]-i!=i-l[i])continue;
		if(r[i]-i==0)continue;
		if(r[i]-i+1!=mx)continue;
		ans++;
	}
	printf("%d\n",ans);

    return 0;
}