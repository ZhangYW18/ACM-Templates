// 大组合数逆元 
// 分母的mod-2次方  (mod为素数)

long long fastpow(long long base,long long index) {  
    long long sum=base,an=1;  
    long long i=index;  
    while (i) {  
        if (i%2) an=(an*sum)%mod;  
        sum*=sum;  
        sum=sum%mod;  
        i/=2;  
    }  
    return an;  
}  
  
long long lucas(long long n,long long m){  
    if (n<m) {  
        return 0;  
    } else return p[n]*(fastpow((p[m]*p[n-m])%mod,mod-2)%mod)%mod;  
}  

//阶乘逆元：inv[n!]=inv[(n+1)!]*(n+1)

    inv[g]=fastpow(fac[g],mod-2);  
    for (i=g-1;i>=0;i--) {  
        inv[i]=inv[i+1]*(i+1);  
        inv[i]%=mod;  
    }  
