#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,mx,cnt;
int vis[26];
char s[maxn];
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d%s",&n,s);
		scanf("%d",&cnt);
		memset(vis,0,sizeof(vis));
		mx=0;
		for(int i=1;i<=cnt;i++){
			char ch[2];
			scanf("%s",ch);
			vis[ch[0]-'a']=1;
		}
		int pre=0;
		for(int i=0;i<n;i++){
			if(vis[s[i]-'a']){
				mx=max(mx,pre);
				pre=0;
			}
			pre++;
		}
		printf("%d\n",mx);
	}


	return 0;
}