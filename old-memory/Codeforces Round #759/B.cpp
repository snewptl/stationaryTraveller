#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,a[maxn];
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		int ed=a[n],cnt=0;
		for(int i=n-1;i>=1;i--){
			if(ed<a[i]){
				cnt++;
				ed=a[i];
			}
		}
		printf("%d\n",cnt);
	}


	return 0;
}