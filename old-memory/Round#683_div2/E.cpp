#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n,a[maxn],ans=1;
int dp[maxn];
int dfs(int cnt,int l,int r,int num){
	if(l>r)return 0;
	if(l==r)return 1;
	int it=lower_bound(a+l,a+r+1,num+(1<<cnt))-a;
	if(it-l<=1)return dfs(cnt-1,it,r,num+(1<<cnt))+it-l;
	if(r-it+1<=1)return dfs(cnt-1,l,it-1,num)+r-it+1;
	return max(dfs(cnt-1,l,it-1,num),dfs(cnt-1,it,r,num+(1<<cnt)))+1;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	printf("%d",n-dfs(30,1,n,0));
    return 0;
}