#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n;
char s[maxn];
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d%s",&n,s+1);
		int ans=0;
		if(n%2==0){
			ans=1;
			for(int i=n/2;i>=2;i--){
				if(s[i]==s[i-1])ans++;
				else break;
			}
			ans*=2;			
		}
		else {
			for(int i=n/2+1;i>=2;i--){
				if(s[i]==s[i-1])ans++;
				else break;
			}
			ans*=2;
			ans++;
		}
		printf("%d\n",ans);
	}


	return 0;
}