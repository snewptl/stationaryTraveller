#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int x;
int a[4],cnt;
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		cnt=0;
		scanf("%d",&x);
		for(int i=1;i<=3;i++)scanf("%d",&a[i]);
		while(x){
			x=a[x];
			cnt++;
		}
		if(cnt==3)puts("YES");
		else puts("NO");
	}


	return 0;
}