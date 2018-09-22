int size[maxn],son[maxn],fa[maxn],top[maxn],dep[maxn],dfn[maxn];
bool visit[maxn];

mem0(visit);
int dfs(int now,int step) {
    visit[now]=1;son[now]=-1;size[now]=1;dep[now]=step;
    int i;
    for (i=head[now];i!=-1;i=edge[i].pre) {
        int to=edge[i].to;
        if (!visit[to]) {
            fa[to]=now;
            size[now]+=dfs(to,step+1);
            if (son[now]==-1||size[to]>size[son[now]]) son[now]=to;
        }
    }
    return size[now];
}

mem0(visit);num=0;
void dfs2(int now,int gr) {
    top[now]=gr;
    dfn[now]=++num;
    visit[now]=1;
    if (son[now]==-1) return;
    dfs2(son[now],gr);
    int i;
    for (i=head[now];i!=-1;i=edge[i].pre) {
        int to=edge[i].to;
        if (!visit[to]) dfs2(to,to);
    }
}

void modify(int u,int v,ll val) {
    int x=top[u],y=top[v];
    while (x!=y) {
        if (dep[x]<dep[y]) swap(x,y),swap(u,v);
        update(dfn[x],dfn[u],val);
        u=fa[x];
        x=top[u];
    }
    if (dep[u]<dep[v]) swap(u,v);
    update(dfn[v],dfn[u],val);
}
