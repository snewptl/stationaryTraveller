#include<bits/stdc++.h>
using namespace std;
const int maxn=5e2+5;
const double eps=1e-9;
int n,m;
int sz[maxn];
vector<int>e[maxn];
double a[maxn][maxn];
int e1[maxn*maxn],e2[maxn*maxn];
void solve(){
	for(int i=1;i<n;i++){
		if(abs(a[i][i])<eps){
			for(int j=i+1;j<n;j++){
				if(abs(a[j][i])>=eps){
					for(int k=1;k<=n;k++)
						swap(a[i][k],a[j][k]);
					break;
				}
			}
		}
		double temp=a[i][i];
		for(int j=i;j<=n;j++)a[i][j]/=temp;
		
		for(int j=i+1;j<n;j++){
			temp=a[j][i];
			for(int k=i;k<=n;k++){
				a[j][k]-=temp*a[i][k];
			}
		}
	}
	for(int i=n-1;i>=1;i--){
		for(int j=i-1;j>=1;j--){
			a[j][n]-=a[i][n]*a[j][i];
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].push_back(y);
		e[y].push_back(x);
		e1[i]=x,e2[i]=y;
		sz[x]++;sz[y]++;
	}
	for(int i=1;i<n;i++){
		a[i][i]=1.0;
		for(auto j:e[i]){
			if(j==n)continue;
			a[i][j]-=1.0/sz[j];
		}
	}
	a[1][n]=1.0;
	solve();
	double ans=0.0;
	vector<double>vec;
	for(int i=1;i<=m;i++){
		double temp=0;
		if(e1[i]!=n)temp+=a[e1[i]][n]/sz[e1[i]];
		if(e2[i]!=n)temp+=a[e2[i]][n]/sz[e2[i]];
		vec.push_back(temp);
	}
	sort(vec.begin(),vec.end());
	for(int i=0,j=m;i<m;i++,j--){
		ans+=vec[i]*j;
	}
	printf("%.3lf\n",ans);
	return 0;
}