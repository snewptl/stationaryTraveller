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
vector<pair<ll,int>>vec;
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d%s",&n,s+1);
		ll ans=n;
		for(int i=1;i<n;i++){
			if(s[i]!=s[i+1]){
				ans+=i;
			}
		}
		printf("%lld\n",ans);
	}


	return 0;
}