void build() {  
    int n,j,i,k;  
    scanf("%d",&k);  
    for (i=1;i<=k;i++)  
        scanf("%d",&b[i]);  
    sort(b+1,b+k+1,cmp);  
    num=0;  
    n=1;  
    for (i=2;i<=k;i++)   
        if (findlca(b[n],b[i])!=b[n]) b[++n]=b[i];  
    int top=0;  
    st[++top]=1;  
    for (i=1;i<=n;i++) {  
        int now=b[i],f=findlca(now,st[top]);  
        while (true) {  
            if (dep[f]>=dep[st[top-1]]) {  
                adde(f,st[top--]);  
                if (st[top]!=f) st[++top]=f;  
                break;  
            }  
            adde(st[top-1],st[top]);  
            top--;  
        }  
        if (st[top]!=now) st[++top]=now;  
    }  
    while (--top) adde(st[top],st[top+1]);  
//    for (i=0;i<num;i++) cout << e[i].from << ' ' << e[i].to << endl;  
    makedp(1,0);  
    printf("%lld\n",dp[1]);  
}  
