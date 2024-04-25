#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
char s[maxn];
int n,cnt,flag;
int vis[30];
void init(){
	cnt=0;
	flag=1;
	for(int i=0;i<26;i++)vis[i]=0;
}
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%s",s);
		n=strlen(s);
		init();
		for(int i=0;i<n;i++){
			if(vis[s[i]-'a']==0)cnt++;
			vis[s[i]-'a']=1;
		}
		for(int i=0;i<n;i++){
			memset(vis,0,sizeof(vis));
			for(int j=0;j<cnt;j++){
				int cur=i+j;
				if(cur>=n)break;
				vis[s[cur]-'a']++;
				if(vis[s[cur]-'a']>=2)flag=0;
			}
		}
		if(flag)puts("YES");
		else puts("NO");
	}


	return 0;
}