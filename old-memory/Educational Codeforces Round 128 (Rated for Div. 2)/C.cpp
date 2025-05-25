#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int pre[maxn][2];
char s[maxn];
int n,ans;
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%s",s+1);
		n=strlen(s+1);
		ans=1e9;
		for(int i=1;i<=n;i++){
			pre[i][0]=pre[i-1][0]+(s[i]=='0');
			pre[i][1]=pre[i-1][1]+(s[i]=='1');
		}	
		int cur=1,sum0=0,sum1=pre[n][1];
		for(int i=1;i<=n;i++){
			if(s[i]=='1')sum1--;
			else sum0++;
			while(sum0>sum1&&cur<=i){
				if(s[cur]=='0')sum0--;
				else sum1++;
				cur++;
			}
			ans=min(ans,max(sum0,sum1));
		}
		printf("%d\n",ans);
	}


	return 0;
}