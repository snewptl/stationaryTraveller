#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int a[105],b[105],n;
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
        scanf("%d",&n);
        int cnta=0,cntb=0;
        for(int i=1;i<=n;i++)scanf("%d",&a[i]),cnta+=a[i]==1;
        for(int i=1;i<=n;i++)scanf("%d",&b[i]),cntb+=b[i]==1;
        int ans1=0,ans2=0;
        ans1=abs(cnta-cntb)+1;
        for(int i=1;i<=n;i++){
            if(a[i]!=b[i])ans2++;
        }
        printf("%d\n",min(ans1,ans2));
	}


	return 0;
}