#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n;
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		puts("2");
		for(int i=1;i<=n;i+=2){
			int cur=i;
			while(cur<=n){
				printf("%d ",cur);
				cur*=2;
			}
		}
		puts("");
	}


	return 0;
}