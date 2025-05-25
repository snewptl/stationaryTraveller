#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
char s[maxn];
int n;
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%s",s);
		n=strlen(s);
		int sum=0;
		for(int i=0;i<n;i++){
			sum+=s[i]-'a'+1;
		}
		int a,b;
		b=min(s[0],s[n-1])-'a'+1;
		a=sum;
		if(n%2)a-=b;
		else b=0;
		int ans;
		if(a>b){
			printf("Alice ");
			ans=a-b;
		}
		else {
			printf("Bob ");
			ans=b-a;
		}
		printf("%d\n",ans);
	}


	return 0;
}