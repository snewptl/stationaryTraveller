#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
char mp[505][505];
char s[505];
int n,m;
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			scanf("%s",s);
			for(int j=1;j<=m;j++)
				mp[i][j]=s[j-1];
		}
		for(int i=1;i<=n;i++)mp[i][1]='X';
		for(int i=1;i<=n;i++){
			while(mp[i][2]=='X'){
				if(i-1&&mp[i-1][2]=='X')mp[i-1][1]='.';
				mp[i][1]='.';
				mp[i-1][2]='X';
				mp[i+1][2]='X';
				i+=2;
			}
		}
		for(int i=1;i<=n;i+=3){
			for(int j=1;j<=m;j++)
			mp[i][j]='X';
		}
		if(n%3==0){
			
			int up=1,now=1;A
			if(mp[n-1][2]=='X')up=2;
			if(mp[n][2]=='X')now=2;
			for(int j=now;j<=m;j++){
				if(mp[n-1][j]=='X')up=j;
				if(mp[n][j]!='X')continue;
				if(up<=now){
					for(int k=now;k<=j;k++)mp[n][k]='X';
					now=j;
				}
				else {
					for(int k=up;k<=j;k++)mp[n][k]='X';
					now=j;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++)printf("%c",mp[i][j]);
			printf("\n");
		}
    }


    return 0;
}
