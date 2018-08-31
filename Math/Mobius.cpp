ll mu[maxn];

void init() {
	num=0;
	int i,j;
	mu[1]=1;
	for (i=2;i<=N;i++) {
		if (!prime[i]) {
			a[++num]=i;
			mu[i]=-1;
		}
		for (j=1;j<=num&&i*a[j]<=N;j++) {
			prime[i*a[j]]=1;
			if (i%a[j]==0) {
				break;
			} else mu[i*prim[j]]=-mu[i];
		}
	}
}
