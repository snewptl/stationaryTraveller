#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,ans;
char s[maxn];
vector<char>vec;
int dis[maxn];
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d%s",&n,s);
		ans=1e9;
		for(char cur='a';cur<='z';cur++){
			vec.clear();
			int sum=0;
			for(int i=0;i<n;i++){
				if(s[i]==cur)continue;
				else {
					vec.push_back(s[i]);
					dis[vec.size()-1]=i;
				}
			}
			int len=vec.size(),flag=1;
			for(int i=0,j=len-1;i<=(len-1)/2;j--,i++){
				if(vec[i]!=vec[len-i-1])flag=0;
				int x,y;
				if(i==0)x=dis[0];
				else x=dis[i]-dis[i-1]-1;
				if(j==len-1)y=n-1-dis[len-1];
				else y=dis[j+1]-dis[j]-1;
				// printf("%d %d\n",x,y);
				if(x>y)swap(x,y);
				
				sum+=y-x;
			}
			if(flag){
				ans=min(ans,sum);
			}
		}
		if(ans==1e9)printf("-1\n");
		else printf("%d\n",ans);

	}


	return 0;
}