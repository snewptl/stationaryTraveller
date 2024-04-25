#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n,a[maxn];
int main(){
    int T;scanf("%d",&T);
    while(T--){
		scanf("%d",&n);
		int mn=1e9;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			mn=min(a[i],mn);
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]==mn)cnt++;
		}
		printf("%d\n",n-cnt);
    }


    return 0;
}