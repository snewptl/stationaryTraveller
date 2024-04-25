#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
ll d,k;
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%lld%lld",&d,&k);
		ll i,j;
		for(i=0;i>0;i+=k){
			if(i*i*2LL>d*d)break;
		}
		i=i-k;int flag=0;
		if(i*i+(i+k)*(i+k)<=d*d)flag=1;
		else flag=2;
		if(flag==1)printf("Ashish\n");
		if(flag==2) printf("Utkarsh\n");

    }
S

    return 0;
}