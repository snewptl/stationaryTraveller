#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=1e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n;
char s[maxn];
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d%s",&n,s);
		int ans=0;
		for(int i=0;i<n;i++){
			if(s[i]!='0')ans+=s[i]-'0'+1;
		}
		if(s[n-1]!='0')ans--;
		printf("%d\n",ans);
	}


	return 0;
}