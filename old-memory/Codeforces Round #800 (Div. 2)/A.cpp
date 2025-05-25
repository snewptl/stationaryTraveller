#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int a,b;
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&a,&b);
		for(int i=1;i<=min(a,b);i++){
			printf("01");
		}
		if(a>b){
			for(int i=b;i<a;i++)printf("0");
		}
		else {
			for(int i=a;i<b;i++)printf("1");
		}
		puts("");
	}


	return 0;
}