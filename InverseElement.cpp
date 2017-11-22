// 大组合数逆元 
// 费马小定理分母的mod-2次方  (mod为素数)

ll fastpow(ll base,ll index) {  
    ll sum=base,ans=1;  
    ll i=index;  
    while (i) {  
        if (i%2) ans=(ans*sum)%mod;  
        sum*=sum;  
        sum=sum%mod;  
        i/=2;  
    }  
    return ans;  
}  
//组合数公式
ll lukas(ll n,ll m){  
    if (n<m) {  
        return 0;  
    } else return p[n]*(fastpow((p[m]*p[n-m])%mod,mod-2)%mod)%mod;  
}  

//阶乘逆元：inv[n!]=inv[(n+1)!]*(n+1)
    fac[1]=1;
	for (i=2;i<=n;i++) {
		fac[i]=(fac[i-1]*i)%mod;
	}
	inv[n]=fastpow(fac[n],mod-2);  
    for (i=n-1;i>=0;i--) {  
        inv[i]=inv[i+1]*(i+1);  
        inv[i]%=mod;  
    }  
    inv[n]=fastpow(fac[n],mod-2);  
    for (i=g-1;i>=0;i--) {  
        inv[i]=inv[i+1]*(i+1);  
        inv[i]%=mod;  
    }  
