//普通快速幂
ll fastpower(ll base,ll index) {
	ll ans,now;
	if (index<0) return 1;
	ans=1;
	now=base;
	ll k=index;
	while (k) {
		if (k%2) ans=ans*now;
		ans%=mod;
		now=now*now;
		now%=mod;
		k/=2;
	}
	return ans;
}
//矩阵快速幂
//需要初始化size
struct Matrix {  
    ll a[size][size];  
};  
  
Matrix operator*(const Matrix &x,const Matrix &y) {  
    int i,j,k;  
    Matrix ans;  
    for (i=0;i<size;i++) {  
        for (j=0;j<size;j++) {  
            ans.a[i][j]=0;  
            for (k=0;k<size;k++) {  
                ans.a[i][j]+=x.a[i][k]*y.a[k][j];  
                ans.a[i][j]%=m;    //求余操作，可加可删
            }  
        }  
    }   
    return ans;  
}  
  
Matrix fastpower(Matrix base,ll index) {  
    Matrix ans,now;  
    int i,j;  
    for (i=0;i<size;i++) {  
        for (j=0;j<size;j++) {  
            if (i==j) ans.a[i][j]=1; else ans.a[i][j]=0;  
        }  
    }  
    now=base;  
    ll k=index;  
    while (k) {  
        if (k%2) ans=ans*now;  
        now=now*now;  
        k/=2;  
    }  
    return ans;  
}  
