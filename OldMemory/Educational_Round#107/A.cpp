#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n;
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
		int cnt=0;
		for(int i=1;i<=n;i++){
			int x;
			scanf("%d",&x);
			if(x!=2)cnt++;
		}
		printf("%d\n",cnt);
    }


    return 0;
}