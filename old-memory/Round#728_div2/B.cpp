#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e4+10;
int n;
int r[maxn][10];
int main(){
    int T;scanf("%d",&T);
    while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=5;j++){
				scanf("%d",&r[i][j]);
			}
		}
		int cur=1;
		for(int i=2;i<=n;i++){
			int temp=0;
			for(int j=1;j<=5;j++){
				temp+=r[cur][j]<r[i][j];
			}
			if(temp<3)cur=i;
		}
		for(int i=1;i<=n;i++){
			if(i==cur)continue;
			int temp=0;
			for(int j=1;j<=5;j++){
				temp+=r[cur][j]<r[i][j];
			}
			if(temp<3){
				cur=0;break;
			}
		}
		if(cur)printf("%d\n",cur);
		else printf("-1\n");
    }


    return 0;
}