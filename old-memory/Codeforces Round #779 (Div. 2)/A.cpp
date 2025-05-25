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
		scanf("%d%s",&n,s);
		int pos=n;
		int ans=0;
		for(int i=n-1;i>=0;i--){
			if(s[i]=='0'){
				if(pos<n){
					ans+=max(0,2-(pos-i-1));	
				}
				pos=i;
			
			}
		}
		printf("%d\n",ans);
	}


	return 0;
}