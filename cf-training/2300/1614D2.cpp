#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,o=2e7,a[100005],f[20000005],g[20000005],vis[20000005],p[2000005],cnt,ans;
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],f[a[i]]++;
	for(int i=2;i<=o;i++)if(!vis[i]){
		int x=o/i;p[++cnt]=i;
		for(int j=i*x;j;j-=i)vis[j]=1,f[j/i]+=f[j];
	}
	for(int i=1;i<=o;i++)g[i]=f[i]*i;
	for(int i=o;i;i--)for(int j=1;j<=cnt&&i*p[j]<=o;j++)g[i]=max(g[i],g[i*p[j]]+(f[i]-f[i*p[j]])*i);
	cout<<g[1];
}