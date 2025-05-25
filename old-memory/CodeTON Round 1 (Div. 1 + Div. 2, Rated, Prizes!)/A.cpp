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
		int mx=0,mn=2e9;
		int l=0,r=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(mx<a[i]){
				mx=a[i];
				r=i;
			}
			if(mn>a[i]){
				mn=a[i];
				l=i;
			}
		}
		printf("%d %d\n",l,r);
	}


	return 0;
}