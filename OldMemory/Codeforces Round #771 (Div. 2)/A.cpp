#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=1e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,a[maxn];
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<=n;i++){
			if(a[i]!=i){
				int j=i;
				while(j<=n&&a[j]!=i)j++;
				for(int k=i;k<=(i+j)/2;k++){
					swap(a[i+j-k],a[k]);
				}
				break;
			}
		}
		for(int i=1;i<=n;i++)printf("%d ",a[i]);
		puts("");
	}


	return 0;
}