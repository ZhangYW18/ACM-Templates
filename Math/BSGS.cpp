// bsgs算法：全称baby-step-giant-step，用于求解形如A^x=B (mod p)的方程的最小整数解(x>=0)。

ll bsgs(ll a,ll b,ll p) {  
    int i;   
    if (p%a==0) return -1;  
//  if (p==1) return 0;  
    ll m=ceil(sqrt(p));  
    ll l=b;  
    mp[l]=1;  
    for (i=1;i<=m;i++) {  
        l*=a;  
        l%=p;  
        mp[l]=i+1;  
    }  
    l=fastpower(a,m,p);ll r=l;  
    for (i=1;i<=m;i++) {  
        if (mp[r]) {  
            ll ans=i*m-mp[r]+1;  
            mp.clear();  
            return ans;  
        }  
        r*=l;  
        r%=p;  
    }  
    mp.clear();  
    return -1;  
}  
