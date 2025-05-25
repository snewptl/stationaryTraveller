#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=1e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n;
char s[3][maxn];
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		scanf("%s%s",s[0],s[1]);
		int flag1=1,flag2=0;
		for(int i=0;i<n;i++){
			if(s[0][i]=='1'&&s[1][i]=='1'){
				flag1=0;
			}
			if(s[0][i]=='0'||s[1][i]=='0'){
				flag2=1;
			}
		}
		if(flag1&&flag2)printf("YES\n");
		else printf("NO\n");
	}


	return 0;
}