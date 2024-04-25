#include<bits/stdc++.h>
using namespace std;
const int maxn=2e2+5;
const double eps=0.0000001;
int n,m,y,x,d,flag;
double e[maxn];
double a[maxn][maxn];
int vis[maxn];
void solve(){
	for(int i=0;i<2*n-2;i++){
		for(int j=i;j<2*n-2;j++){
			if(abs(a[j][i])>eps){
				for(int k=0;k<=2*n-2;k++)
					swap(a[j][k],a[i][k]);
				break;
			}
		}
		if(abs(a[i][i])<=eps){
			if(!vis[i])continue;
			flag=1;return;
		}
		double temp=a[i][i];
		for(int j=i;j<=2*n-2;j++)
			a[i][j]/=temp;
		for(int j=i+1;j<2*n-2;j++){
			double temp=a[j][i];
			for(int k=i;k<=2*n-2;k++){
				a[j][k]-=temp*a[i][k];
			}
		}
	}
	for(int i=n*2-3;i>=0;i--){
		if(!vis[i])continue;
		a[i][n*2-2]/=a[i][i];
		for(int j=i-1;j>=0;j--){
			a[j][n*2-2]-=a[i][n*2-2]*a[j][i];
		}
	}
}
void bfs(int u){
	queue<int>q;
	q.push(u);
	while(!q.empty()){
		int p=q.front();q.pop();
		for(int i=1;i<=m;i++){
			if(e[i]<eps)continue;
			int temp=(p+i)%(2*n-2);
			if(!vis[temp]){
				q.push(temp);
				vis[temp]=1;
			}
		}
	}
}
int main(){
	int T;scanf("%d",&T);
	while(T--){
		flag=0;
		scanf("%d%d%d%d%d",&n,&m,&y,&x,&d);
		for(int i=0;i<2*n-2;i++)vis[i]=0;
		if(d==1)x=2*(n-1)-x;
		for(int i=1;i<=m;i++){
			scanf("%lf",&e[i]);
			e[i]/=100;
		}		
		if(x==y){
			printf("0.00\n");continue;
		}
		vis[x]=1;bfs(x);
		for(int i=0;i<2*n-2;i++){
			for(int j=0;j<=2*n-2;j++)
				a[i][j]=0.0;
		}
		for(int i=0;i<2*n-2;i++){
			a[i][i]=1.0;
			if(i==y||i==(2*(n-1)-y))continue;
			for(int j=1;j<=m;j++){
				a[i][(j+i)%(2*n-2)]-=e[j];
				a[i][2*n-2]+=e[j]*j;
			}

		}
		solve();
		
		if(!flag)printf("%.2f\n",a[x][2*n-2]);
		else printf("Impossible !\n");
	}

	return 0;
}