#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
char s[maxn];
char ans[maxn];
int n;
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d%s",&n,s+1);
		if(s[1]=='9'){
			for(int i=0;i<=n;i++)ans[i]=1;
			for(int i=n;i>=1;i--){
				if(ans[i]>=s[i]-'0')ans[i]-=s[i]-'0';
				else ans[i]=ans[i]-s[i]+'0'+10,ans[i-1]--;
			}
			for(int i=1;i<=n;i++)printf("%d",ans[i]);
		}
		else {
			for(int i=1;i<=n;i++)printf("%c",'9'-s[i]+'0');
		}
		puts("");
	}


	return 0;
}