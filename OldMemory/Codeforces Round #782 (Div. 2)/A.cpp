#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,r,b;
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		cin>>n>>r>>b;
		int res=(r-1)/(b+1);
		int cnt1=r-res*(b+1);
		for(int i=1;i<=b;i++){
			if(cnt1){
				for(int j=1;j<=res+1;j++)putchar('R');
				cnt1--;
			}
			else {
				for(int j=1;j<=res;j++)putchar('R');
			}
			putchar('B');
		}
		if(cnt1)for(int i=1;i<=res+1;i++)putchar('R');
		else for(int i=1;i<=res;i++)putchar('R');
		puts("");
	}


	return 0;
}