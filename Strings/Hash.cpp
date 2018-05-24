ull seed1=26,seed2=1e9+7;  
  
ull hash() {  
    ull sum=seed1;  
    for (int i=0;i<26;i++) {  
        sum*=seed2;  
        sum+=a[i];  
    }  
    return sum;  
}  

//可截取区间的哈希
ll hash() {
    fac[0]=1;hash[0]=0;
	for (int i=1;i<=n;i++) {
		fac[i]=(fac[i-1]*inf)%mod;
		hash[i]=(hash[i-1]*inf+(s[i]-'a')%mod;
	}
}
ll gethash(int l,int r) {
    return (((hash[r]-hash[l-1]*fac[r-l+1])%mod)+mod)%mod;
}
