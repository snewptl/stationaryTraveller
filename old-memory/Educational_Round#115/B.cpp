#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=1e3+5;
const ll mod=998244353;
const double eps=1e-10;
int a[maxn][10];
vector<int>vec;
int n;
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		int flag=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=5;j++){
				scanf("%d",&a[i][j]);
			}
		}
		for(int i=1;i<=5;i++){
			vec.clear();
			for(int j=1;j<=n;j++){
				if(a[j][i])vec.push_back(j);
			}
			for(int j=i+1;j<=5;j++){
				int sum=0,bt=0;
				for(int k=1;k<=n;k++){
					if(a[k][j])sum++;
				}
				for(auto k:vec){
					if(a[k][j])bt++;
				}
				if(sum+vec.size()-bt==n&&sum>=n/2&&vec.size()>=n/2){
					flag=1;
				}
			}
		}
		if(flag)printf("YES\n");
		else printf("NO\n");
	}


	return 0;
}