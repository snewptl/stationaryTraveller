#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n;
char s[105];
int mp[105][105];
vector<int>vec;
int main(){
    int T;scanf("%d",&T);
    while(T--){
		memset(mp,0,sizeof(mp));
		scanf("%d%s",&n,s);
		vec.clear();
		for(int i=0;i<n;i++){
			if(s[i]=='2')vec.push_back(i+1);
		}
		if(vec.size()==1||vec.size()==2)printf("NO\n");
		else {
			printf("YES\n");
			for(int i=1;i<vec.size();i++){
				mp[vec[i-1]][vec[i]]=1;
				mp[vec[i]][vec[i-1]]=-1;
			}
			if(vec.size()){
				mp[vec[vec.size()-1]][vec[0]]=1;
				mp[vec[0]][vec[vec.size()-1]]=-1;				
			}			
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(i==j)printf("X");
					else if(mp[i][j]==1)printf("+");
					else if(mp[i][j]==-1)printf("-");
					else printf("=");
				}
				printf("\n");
			}			
		}


    }


    return 0;
}