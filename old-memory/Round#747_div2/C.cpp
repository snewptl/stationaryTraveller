#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=3e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n;
char s[maxn];
char ch[10];
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d%s%s",&n,ch,s+1);
		int tot=2,pos;
		for(int i=n;i>=1;i--){
			if(i*2<=n)break;
			if(s[i]==ch[0]){
				tot=1,pos=i;
				break;
			}
		}
		int flag=0;
		for(int i=1;i<=n;i++){
			if(s[i]!=ch[0])flag=1;
		}
		if(!flag)tot=0;
		if(tot==0)printf("0\n");
		else if(tot==1)printf("1\n%d\n",pos);
		else printf("2\n%d %d\n",n,n-1);
	}


	return 0;
}