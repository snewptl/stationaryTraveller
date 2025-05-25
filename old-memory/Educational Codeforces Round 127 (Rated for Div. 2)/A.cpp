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
		scanf("%s",s);
		int n=strlen(s);
		int pre=0,flag=1;
		for(int i=1;i<n;i++){
			if(s[i]==s[pre]);
			else {
				int cnt=i-pre;
				if(cnt==1)flag=0;
				pre=i;

			}
		}
		if(pre==n-1)flag=0;
		if(flag)puts("YES");
		else puts("NO");
	}


	return 0;
}