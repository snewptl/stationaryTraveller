#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
bool pri(int x){
	int sq=sqrt(x+0.5);
	for(int i=2;i<=sq;i++){
		if(x%i==0)return true;
	}
	return false;
}
int main(){
    int T;scanf("%d",&T);
    while(T--){
        int n,ans=0;
		scanf("%d",&n);
		if(n==1)ans=0;
		else if(n==2)ans=1;
		else if(n==3)ans=2;
		else{
			if(!pri(n))ans=3;
			else if(n%2==0)ans=2;
			else ans=3;
		}
		printf("%d\n",ans);
    }


    return 0;
}