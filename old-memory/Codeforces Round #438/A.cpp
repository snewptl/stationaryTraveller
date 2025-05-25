#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=1e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n;
char s[105][5];
char mb[5];
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		int ans=0;
		scanf("%s%d",mb,&n);
		for(int i=1;i<=n;i++){
			scanf("%s",s[i]);
			if(s[i][0]==mb[0]&&s[i][1]==mb[1])ans=1;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(s[i][1]==mb[0]&&s[j][0]==mb[1])ans=1;
			}
		}
		if(ans)printf("YES\n");
		else printf("NO\n");
	}


	return 0;
}