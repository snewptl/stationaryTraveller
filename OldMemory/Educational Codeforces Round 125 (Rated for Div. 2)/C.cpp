#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=5e5+5;
const ll mod=998244353;
const double eps=1e-10;
char s[maxn];
int pre[maxn];
int n;
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		scanf("%s",s+1);
		int i=1,ans=0,rem=0;
		while(i<n){
			if(s[i]=='('){
				ans++;
				i+=2;
			}
			else {
				int flag=0;
				for(int j=i+1;j<=n;j++){
					if(s[j]==')'){
						flag=1;
						ans++;
						i=j+1;
						break;
					}
				}
				if(!flag)break;
			}
		}
		rem=n-i+1;
		printf("%d %d\n",ans,rem);
	}


	return 0;
}