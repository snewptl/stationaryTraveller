#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
const double eps=1e-7;
int a[maxn];
double ans=1.0;
int main(){
    int T;scanf("%d",&T);
    while(T--){
        int n,p;
		ans=1.0;
		scanf("%d%d",&n,&p);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		int ed=n;
		for(;ed>=1;ed--)if(a[ed]!=ed)break;
		for(int i=1;i<=p;i++){
			int r;double x;
			scanf("%d%lf",&r,&x);
			if(r>=ed){
				ans*=1.0-x;	
			}
		}
		if(ed==0)printf("1.000000\n");
		else printf("%.6lf\n",1.0-ans);
    }


    return 0;
}