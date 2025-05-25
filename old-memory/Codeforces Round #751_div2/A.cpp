#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=1e5+5;
const ll mod=998244353;
const double eps=1e-10;
char s[maxn];
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%s",s);
		int n=strlen(s);
		char mn='z';
		for(int i=0;i<n;i++){
			mn=min(mn,s[i]);
		}
		printf("%c ",mn);
		for(int i=0;i<n;i++){
			if(mn==s[i]){
				mn=0;
				continue;
			}
			printf("%c",s[i]);
		}
		printf("\n");
	}


	return 0;
}