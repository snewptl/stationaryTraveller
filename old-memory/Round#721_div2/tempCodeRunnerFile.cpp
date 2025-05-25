    int T;scanf("%d",&T);
    while(T--){
		scanf("%d%s",n,s);
		for(int i=0;i<n/2;i++){
			if(s[i]=='0')cnt1++;
		}
		for(int i=(n-1)/2+1;i<n;i++){
			if(s[i]=='0')cnt2++;
		}
		int mid=(n%2==0?1:s[n/2]);
		int d=dfs(cnt1,cnt2,mid,)
    }