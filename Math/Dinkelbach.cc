struct Pack{
	db a,b,d;
};
Pack p[maxn];

bool cmp(Pack x,Pack y) {
	return x.d<y.d;
}

db Dinkelbach(int n,int k) {
	db ans=0,l;
 	while (true) {
		l=ans;
	  	int i; db s0,s1;
	  	for (i=1;i<=n;i++) {
			p[i].d=p[i].a-l*p[i].b;
		}
		sort(p+1,p+n+1,cmp);
		s0=s1=0;
		for (i=k+1;i<=n;i++) {
			s0+=p[i].a;s1+=p[i].b;
		}
		ans=s0/s1;
		if (fabs(l-ans)<eps) return ans;
  	}
}

