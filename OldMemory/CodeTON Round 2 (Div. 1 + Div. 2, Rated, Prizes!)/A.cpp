#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,m;
string s,t;
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		cin>>n>>m;
		cin>>s>>t;
		int len=1;
		while(len<=min(m,n)&&s[n-len]==t[m-len]){
			len++;
		}
		len--;
		int flag[2]={0,0};
		for(int i=0;i<n-len;i++)flag[s[i]-'0']=1;
		int ans=1;
		if(len<m-1||(len==m-1&&!flag[t[0]-'0']))ans=0;
		if(ans)puts("YES")	;
		else puts("NO");
	}


	return 0;
}