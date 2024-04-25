#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int cnt[2];
int n,p[maxn];
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		cnt[0]=cnt[1]=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&p[i]);
			cnt[p[i]%2]++;
		}
		printf("%d\n",min(cnt[0],cnt[1]));
	}


	return 0;
}