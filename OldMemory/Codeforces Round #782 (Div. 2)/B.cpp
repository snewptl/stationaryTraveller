#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
char s[maxn];
int n,k,a[maxn];
int cnt[maxn];
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		scanf("%s",s);
		int n=strlen(s);
		for(int i=0;i<n;i++)cnt[i]=0;
		int cur=k;
		for(int i=0;i<n;i++){
			a[i]=s[i]-'0';
			if(cur%2)a[i]^=1;
			if(a[i]==0&&k)a[i]=1,k--,cnt[i]++;
		}
		if(k%2)a[n-1]=0;
		cnt[n-1]+=k;
		for(int i=0;i<n;i++)printf("%d",a[i]);
		puts("");
		for(int i=0;i<n;i++)printf("%d ",cnt[i]);
		puts("");	
	}


	return 0;
}