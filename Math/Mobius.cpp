ll mu[maxn],sum[maxn],p[maxn];
int num;

void init() {
	num=0;
	int i,j;
	mu[1]=1;
	for (i=2;i<=N;i++) {
		if (!prime[i]) {
			p[++num]=i;
			mu[i]=-1;
		}
		for (j=1;j<=N&&i*a[j]<=N;j++) {
			if (i%p[j]==0) {
				mu[i*p[j]]=0;
			} else mu[i*p[j]]=-mu[i];
		}
	}
}
