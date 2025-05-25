#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n;
vector<pii>opt;
int main(){
	int T=1;//scanf("%d",&T);
	while(T--){
		opt.clear();
		scanf("%d",&n);
		if(n==1){
			puts("1");
			puts("1 1");
		}
		else {
			int x=0;
			if(n%3==1)opt.push_back({n,n}),n--;
			if(n%3==0)opt.push_back({n,n}),n--;
			x=n/3;			
			for(int i=1;i<=x;i++){
				opt.push_back({i,x+1-i});
			}
			for(int i=1;i<=x+1;i++){
				opt.push_back({n-i+1,n-(x+1-i)});
			}
			printf("%d\n",opt.size());
			for(auto it:opt){
				printf("%d %d\n",it.first,it.second);
			}
		}

		
		

	}


	return 0;
}