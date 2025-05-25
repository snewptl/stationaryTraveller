#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n,s;
int main(){
    int T;scanf("%d",&T);
    while(T--){
		scanf("%d%d",&n,&s);
		int mid=(1+n)/2;
		int cur=s/(n-mid+1);
		printf("%d\n",cur);
    }


    return 0;
}