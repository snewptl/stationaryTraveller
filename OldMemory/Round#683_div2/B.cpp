#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int n,m,k;
int a[105][105];
int main(){
    int T;scanf("%d",&T);
    while(T--){
		k=0;
		int ans=0,mn=1e9;
        scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				scanf("%d",&a[i][j]);
				if(a[i][j]<0)k++;
				ans+=abs(a[i][j]);
				mn=min(mn,abs(a[i][j]));
			}
		}
		if(k%2)ans-=mn*2;
		printf("%d\n",ans);

    }


    return 0;
}