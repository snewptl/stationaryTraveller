#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,a[maxn];
int sum[2],pos[2];
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		if((n%2)){
			puts("Mike");
		}
		else {
			sum[0]=sum[1]=1e9;
			pos[0]=pos[1]=0;
			for(int i=1;i<=n;i++){
				if(sum[i%2]>a[i]){
					sum[i%2]=a[i];
					pos[i%2]=i;
				}
			}
			if(sum[1]>sum[0])puts("Mike");
			else if(sum[1]==sum[0]){
				if(pos[1]>pos[0])puts("Mike");
				else puts("Joe");
			}
			else puts("Joe");
		}
	}


	return 0;
}