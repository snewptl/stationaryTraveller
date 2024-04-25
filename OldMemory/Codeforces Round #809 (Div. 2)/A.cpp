#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
char s[55];
int n,m,a[maxn];
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<=m;i++)s[i]='B';
		for(int i=1;i<=n;i++){
			int cur=min(a[i],m-a[i]+1);
			if(s[cur]=='B')s[cur]='A';
			else s[m-cur+1]='A';
		}
		for(int i=1;i<=m;i++)putchar(s[i]);
		puts("");
	}


	return 0;
}