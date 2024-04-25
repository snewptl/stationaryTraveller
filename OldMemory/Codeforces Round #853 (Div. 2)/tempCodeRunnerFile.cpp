        for(int i=1;i<=s[n];i++)pre[i]+=pre[i-1];
        for(int i=1,j;i<=s[n];i=j+1){
            j=s[n]/(s[n]/i);
            ll sum=1ll*(i+j)*(j-i+1)/2%mod;
            int k=s[n]/i;
            for(int j=1;j<=min(k-1,s[n]/k);j++){
                ans+=sum*(pre[j*k+j]-pre[j*k])%mod;
                ans%=mod;
            }
            if(k-1<s[n]/k){
                ans+=sum*(pre[s[n]]-pre[(k-1)*k+(k-1)]);
                ans%=mod;
            }
        }