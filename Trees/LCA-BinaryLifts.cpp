void dfs(int now,int fa) {   
    visit[now]=1;    
    mfa[now][0]=fa;  
    for (int i=1;mfa[now][i-1]!=0;i++)  
        mfa[now][i]=mfa[mfa[now][i-1]][i-1];   
    for (int i=head[now];i!=-1;i=edge[i].pre) {    
        int to=edge[i].to;    
        if (!visit[to])    
            dfs(to,now);    
    }    
}    
     
int findlca(int a,int b) {    
    int x=a,y=b,i;  
    if (dep[x]>dep[y]) swap(x,y);  
    for (i=18;i>=0;i--)
        if (dep[fa[y][i]]>=dep[x]) y=fa[y][i];  
    if (y==x) return x;  
    for (i=18;i>=0;i--)
        if (fa[y][i]!=fa[x][i]&&fa[x][i]!=0&&fa[y][i]!=0)
            x=fa[x][i],y=fa[y][i];  
    return fa[x][0];  
}  
