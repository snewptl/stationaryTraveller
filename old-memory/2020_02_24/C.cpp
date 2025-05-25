#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=20000+10;
int s[maxn],ans[maxn],sum[30],n,m;
char a[maxn];
int div(int pos){
	if(s[m]<pos)return 0;
	int l=1,r=m,mid,ans=r;
	while(l<=r){
		mid=(l+r)>>1;
		if(s[mid]>=pos)	r=mid-1,ans=mid;
		else l=mid+1;
	}
	return m-ans+1;
}
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		scanf("%s",a+1);
		memset(sum,0,sizeof(sum));
		for(int i=1;i<=m;++i)scanf("%d",&s[i]);
		sort(s+1,s+m+1);
		for(int i=1;i<=n;++i)
			ans[i]=1+div(i);
		for(int i=1;i<=n;++i)
			sum[a[i]-'a']+=ans[i];
		for(int i=0;i<26;++i)printf("%d ",sum[i]);
		printf("\n");
	}
	return 0;
}