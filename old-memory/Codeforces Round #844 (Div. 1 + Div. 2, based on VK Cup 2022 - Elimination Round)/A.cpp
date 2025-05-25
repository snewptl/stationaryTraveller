#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int w,d,h;
int a,b,f,g;
int dis(pii x,pii y){
    return abs(x.first-y.first)+abs(x.second-y.second);
}
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
        cin>>w>>d>>h;
        cin>>a>>b>>f>>g;
        pii x,y={f,g};
        x={a,0};
        int d1=dis(x,y)+b;
        x={a,d};
        int d2=dis(x,y)+d-b;
        x={0,b};
        int d3=dis(x,y)+a;
        x={w,b};
        int d4=dis(x,y)+w-a;        
        int ans=min(min(d1,d2),min(d3,d4))+h;
        cout<<ans<<'\n';       
	}


	return 0;
}