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
	int T=1;//scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<=n;i++){
			int res=15,up=32768;
			for(int j=0;j<15;j++){
				int temp=j;
				temp+=(up-a[i]%up)%up;
				up/=2;
				res=min(res,temp);
			}
			printf("%d ",res);
		}
	}


	return 0;
}