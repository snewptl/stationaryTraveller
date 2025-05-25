#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n,a[6],b[6];
int flag;
void dfs(int dep){
	if(dep==4){
		int temp=1;
		for(int i=0;i<4;i++){
			int k=a[i]+a[(i+1)%4];
			if(k>b[i])temp=0;
			if(n-2+k<b[i])temp=0;
		}
		if(temp)flag=1;
		return ;
	}
	a[dep]=1;
	dfs(dep+1);
	a[dep]=0;
	dfs(dep+1);
}
int main(){
    int T;scanf("%d",&T);
    while(T--){
		flag=0;
		scanf("%d",&n);
        for(int i=0;i<4;i++)scanf("%d",&b[i]);
		dfs(0);
		if(flag)printf("YES\n");
		else printf("NO\n");
    }


    return 0;
}