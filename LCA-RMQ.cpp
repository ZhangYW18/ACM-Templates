int head[maxn],in[2*maxn],out[2*maxn],a[maxn*2],d[maxn*2];  
int mn[maxn*2][20];

//dfs序+RMQ实现LCA
void dfs(int now,int step) {  
    visit[now]=1;  
    a[++dfn]=now;d[dfn]=step;  
    in[now]=out[now]=dfn; 
    for (int i=head[now];i!=-1;i=edge[i].pre) {  
        int to=edge[i].to;  
        if (!visit[to]) {  
            dfs(to,step+1);  
            out[now]=++dfn;  
            a[dfn]=now;d[dfn]=step;  
        }  
    }  
}  
  
void init(int n) {  
    int i,j;  
    for (i=1;i<=n;i++) mn[i][0]=i;  
    for (j=1;(1<<j)<=n;j++) {  
        for (i=1;i+(1<<j)-1<=n;i++) {  
            int p=mn[i][j-1],q=mn[i+(1<<(j-1))][j-1];  
            mn[i][j]=d[p]<d[q]?p:q;  
        }  
    }  
}  
  
int findlca(int l,int r) {  
    int k=0;  
    if (l>r) swap(l,r);  
    while (1<<(k+1)<=(r-l+1)) k++;  
    int p=mn[l][k],q=mn[r-(1<<k)+1][k];  
    return d[p]<d[q]?a[p]:a[q];  
}  

 lca=findlca(in[x],in[y]);  
