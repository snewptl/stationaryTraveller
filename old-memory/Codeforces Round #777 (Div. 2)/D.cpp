#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int x,d;
bool ispri(int x){
	for(int i=2;i*i<=x;i++){
		if(x%i==0)return false;
	}
	return true;
}
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&x,&d);
		int k=0,num=0,cnt=0;
		int nx=x,nd=d;
		while(nx%d==0)nx/=d,k++;
		for(int i=2;i*i<=nd;i++){
			if(nd%i==0){
				num++;
				while(nd%i==0)nd/=i,cnt++;
			}
		}
		if(nd!=1)cnt++,num++;
		if(k==1)puts("NO");
		else if(cnt==1){
			if(ispri(nx))puts("NO");
			else puts("YES");
		}
		else if(num==1){
			if(k==2){
				if(ispri(nx))puts("NO");
				else puts("YES");
			}
			else if(k==3){
				if(ispri(nx)&&d==1ll*nx*nx)puts("NO");
				else puts("YES");
			}
			else puts("YES");
		}
		else {
			if(k==2){
				if(ispri(nx))puts("NO");
				else puts("YES");
			}
			else puts("YES");
		}
		
	}


	return 0;
}