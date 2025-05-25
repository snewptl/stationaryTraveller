#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
double ans;
int n,cnty,cntx;
int x[maxn],y[maxn];
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
		cnty=cntx=0;ans=0.0;
		for(int i=1;i<=2*n;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			a=abs(a),b=abs(b);
			if(a==0)y[++cnty]=b;
			if(b==0)x[++cntx]=a;
		}
		sort(x+1,x+n+1);
		sort(y+1,y+n+1);
		for(int i=n;i>=1;i--){
			ans+=sqrt(1.0*x[i]*x[i]+1.0*y[i]*y[i]);
		}
		printf("%.9lf\n",ans);
    }


    return 0;
}