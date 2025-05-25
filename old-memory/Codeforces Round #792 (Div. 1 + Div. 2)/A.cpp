#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n;
vector<int>vec;
char s[15];
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%s",s);
		n=strlen(s);
		if(n==2){
			printf("%c\n",s[n-1]);
		}
		else {
			char mn='9';
			for(int i=0;i<n;i++)mn=min(mn,s[i]);
			printf("%c\n",mn);
		}
		
	}


	return 0;
}