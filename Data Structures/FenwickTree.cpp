int lowbit(int a) {
    return (a&(-a));
}

ll getsum(int tt) {
    ll sum=0;
    for (int t=tt;t;t-=lowbit(t))
        sum+=f[t];
    return sum;
}

void update(int tt,ll c,int n) {
    int t=tt;
    for (int t=tt;t<=n;t+=lowbit(t))
        f[t]+=c;
}
