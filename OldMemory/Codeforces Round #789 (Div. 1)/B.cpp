#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e6+5;
const ll mod=998244353;
const double eps=1e-10;
int n,m,sz;
char s[maxn];
int ans[maxn];
int mk[maxn];
int col[maxn],row[maxn];
void init(){
	for(int i=0;i<=m;i++)mk[i]=0;
	for(int i=0;i<sz;i++){
		ans[i]=0;
		col[i]=row[i]=0;
	}
}
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d%d%s",&n,&m,s);
		sz=n*m;
		init();
		for(int i=0;i<sz;i++){
			if(s[i]=='1'){
				if(mk[i%m])continue;
				mk[i%m]=1;
				for(int j=0;j<n;j++){
					int temp=i+j*m;
					if(temp>=sz)break;
					col[temp]=1;
				}
			}
		}
		for(int i=0;i<sz;i++){
			col[i]+=col[i-1];
			if(i>=m)
				ans[i]+=col[i]-col[i-m];
			else 
				ans[i]=col[i];
		}

		int pre=0;
		for(int i=0;i<sz;i++){
			if(s[i]=='1'){
				for(int j=max(i,pre);j<min(i+m,sz);j++){
					row[j]=1;
				}
				pre=i+m;
			}
		}
		for(int i=0;i<sz;i++){
			if(i>=m)
				row[i]+=row[i-m];
			ans[i]+=row[i];
		}

		for(int i=0;i<sz;i++){
			printf("%d ",ans[i]);
		}
		puts("");
		
	}


	return 0;
}