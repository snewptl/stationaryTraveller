#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=100+10;
int h[maxn];
int n,k,p;
int main(){
    int T;scanf("%d",&T);
    while(T--){
		scanf("%d%d",&n,&k);p=-1;
		for(int i=1;i<=n;i++)scanf("%d",&h[i]);
		for(int i=1;i<n;i++){
			if(p!=-1)break;
			while(h[i]<h[i+1]){
				if(p!=-1)break;
				k--;
				h[i]+=1;
				if(k<=0)p=i;
				if(p!=-1)break;
				int j=i-1;
				while(j&&h[j]<h[j+1]){
					k--;
					h[j]++;
					if(k<=0)p=j;
					j--;
					if(p!=-1)break;
				}
			}
		}
		printf("%d\n",p);
	
    }


    return 0;
}