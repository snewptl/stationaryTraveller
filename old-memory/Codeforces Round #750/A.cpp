#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=1e5+5;
const ll mod=998244353;
const double eps=1e-10;
int a,b,c;
int ans;
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&a,&b,&c);
		if(a==0){
			if(c%2==0){
				if(b==1){
					ans=2;
				}
				else ans=0;
			}
			else {
				ans=1;
			}
		}
		else if(a==1){
			if(c%2==0)ans=1;
			else ans=0;
		}
		else if(a==2){
			if(c%2==0)ans=0;
			else ans=1;
		}
		else {
			if((a+c)%2)ans=1;
			else ans=0;
		}
		printf("%d\n",ans);
	}


	return 0;
}