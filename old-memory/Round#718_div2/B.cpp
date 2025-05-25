#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n,m;
int b[105][105],vis[105][105];
int k[105];
set<pair<int,int>>s;
int main(){
    int T;scanf("%d",&T);
    while(T--){
		s.clear();
        scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++){
			k[i]=0;
			for(int j=0;j<m;j++){
				scanf("%d",&b[i][j]);
				s.insert(make_pair(b[i][j],i*m+j));
			}
			sort(b[i],b[i]+m);
		}
		int temp=0;
		for(auto x:s){
			int h=x.second/m;
			int l=x.second%m;
			for(int i=0;i<n;i++){
				if(i!=h)vis[i][temp]=b[i][m-1-temp+k[i]];
				else vis[i][temp]=x.first,k[i]++;
			}
			temp++;
			if(temp>=m)break;
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				printf("%d ",vis[i][j]);
			}
			printf("\n");
		}
    }


    return 0;
}