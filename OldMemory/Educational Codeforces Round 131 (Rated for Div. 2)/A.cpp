#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int a[5][5],sum;
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		sum=0;
		for(int i=0;i<2;i++)
		for(int j=0;j<2;j++){
			scanf("%d",&a[i][j]);
			sum+=a[i][j];
		}
		if(sum==0)puts("0");
		else if(sum<4)puts("1");
		else puts("2");
	}


	return 0;
}