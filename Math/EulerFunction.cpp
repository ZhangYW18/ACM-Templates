void init() {
	num=0;
	memset(prime,0,sizeof(prime));
	int i,j;
	euler[1]=1;
	for (i=2;i<=maxn;i++) {
		if (!prime[i]) {
			a[++num]=i;
			euler[i]=i-1;
		}
		for (j=1;j<=num&&i*a[j]<=maxn;j++) {
			prime[i*a[j]]=1;
			if (i%a[j]==0) {
				euler[i*a[j]]=euler[i]*a[j];
				break;
			} else euler[i*a[j]]=euler[i]*(a[j]-1);
		}
	}
}
