struct query {  
    int p,a,b,id,l[2];  
    db g[2];  
    bool operator< (const query &x) const {  
        return id<x.id;  
    }  
};  
query q[maxn],tem[maxn];   

void cdq(int l,int r,int p) {  
    if (l==r) {  
        if (q[l].l[p] < 1)   
            q[l].l[p] = 1, q[l].g[p] = 1.0;  
        return;  
    }  
    int mid=(l+r)/2;  
    memcpy(tem+l,q+l,sizeof(query)*(r-l+1));  
    int h=l,t=mid+1;  
    for (int i=l;i<=r;i++)  (tem[i].p<=mid?q[h++]:q[t++])=tem[i];  
    cdq(l,mid,p);  
    num++;  
    h=l,t=mid+1;  
    for (int i=mid+1;i<=r;i++)  
    {  
        while (h<=mid&&q[h].id<q[i].id)   
            update(q[h].b,q[h].l[p],q[h].g[p]),h++;  
        Tree now=gettree(q[i].b);  
        if (!now.l) continue;  
        if (now.l+1>q[i].l[p])  q[i].l[p]=now.l+1,q[i].g[p]=now.g;  
            else if (now.l+1==q[i].l[p]) q[i].g[p]+=now.g;  
    }  
    cdq(mid+1,r,p);  
    merge(q+l,q+mid+1,q+mid+1,q+r+1,tem+l);  
    memcpy(q+l,tem+l,sizeof(query)*(r-l+1));  
}  
