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
ull fac[maxn],hsh[maxn],fac2[maxn],hsh2[maxn];
unordered_map<ll,int> mp,mp2;
const ull seed=100001651,seed2=63218479;
void myhash(int n) {
    fac[0]=fac2[0]=1;hsh[0]=hsh2[0]=0;
	for (int i=1;i<=n;i++) {
		fac[i]=fac[i-1]*seed;
		hsh[i]=hsh[i-1]*seed+s[i];
		fac2[i]=fac2[i-1]*seed2;
		hsh2[i]=hsh2[i-1]*seed2+s[i];
	}
}

ull gethash(int l,int r) {
    return (((hash[r]-hash[l-1]*fac[r-l+1])%mod)+mod)%mod;
}
