#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=1e6+5;
const ll mod=998244353;
const double eps=1e-10;
int n,m,q;
vector<char>mp[maxn];
char s[maxn];
int vis[maxn];
int sum[maxn];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%s",s);
		for(int j=0;j<m;j++)mp[i].push_back(s[j]);
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<m;j++){
			if(mp[i-1][j]=='X'&&mp[i][j-1]=='X')vis[j]=1,sum[j]++;
		}
	}
	for(int i=1;i<m;i++)sum[i]+=sum[i-1];
	scanf("%d",&q);
	while(q--){
		int l,r;
		scanf("%d%d",&l,&r);
		l--,r--;
		int temp=sum[r]-sum[l];
		if(temp)printf("NO\n");
		else printf("YES\n");
	}

	return 0;
}