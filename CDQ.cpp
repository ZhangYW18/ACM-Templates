struct query {  
    int type,pos,id,pre,val;  
    bool operator< (const query &x) const {  
        return pos<x.pos || (pos==x.pos&&type<x.type);  
    }  
};  
query q[maxn*7],tem[maxn*7];  
  
int lowbit(int x) {  
    return x&(-x);  
}  
  
ll getsum(int tt) {  
    ll sum=0;  
    for (int t=tt;t;t-=lowbit(t))   
        sum+=f[t];  
    return sum;  
}  
  
void update(int tt,ll c) {  
    int t=tt;  
    for (int t=tt;t<=N;t+=lowbit(t))  
        f[t]+=c;  
}  
  
void cdq(int l,int r) {  
    int mid=(l+r)/2;  
    if (l!=r) cdq(l,mid),cdq(mid+1,r);  
    int h=l,t=mid+1,cnt=0;  
    while (h<=mid&&t<=r) {  
        if (q[h]<q[t]) {  
            if (q[h].type==1) update(q[h].id,q[h].pre);  
            tem[cnt++]=q[h++];  
        } else {  
            if (q[t].type==2) ans[q[t].val]-=getsum(q[t].pre)-getsum(q[t].id-1);  
                else if (q[t].type==3) ans[q[t].val]+=getsum(q[t].pre)-getsum(q[t].id-1);  
            tem[cnt++]=q[t++];  
        }  
    }  
    int o=h;  
    for (;h<=mid;h++)  
        tem[cnt++]=q[h];  
    for (;t<=r;t++) {  
        if (q[t].type==2) ans[q[t].val]-=getsum(q[t].pre)-getsum(q[t].id-1);  
            else if (q[t].type==3) ans[q[t].val]+=getsum(q[t].pre)-getsum(q[t].id-1);  
        tem[cnt++]=q[t];  
    }  
    for (int i=l;i<o;i++) if (q[i].type==1) update(q[i].id,-q[i].pre);  
    for (int i=0;i<cnt;i++) q[l+i]=tem[i];  
}  
