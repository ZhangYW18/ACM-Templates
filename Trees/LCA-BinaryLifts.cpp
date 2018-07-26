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
        if (dep[mfa[y][i]]>=dep[x]) y=mfa[y][i];  
    if (y==x) return x;  
    for (i=18;i>=0;i--)
        if (mfa[y][i]!=mfa[x][i]&&mfa[x][i]!=0&&mfa[y][i]!=0)
            x=mfa[x][i];y=mfa[y][i];  
    return mfa[x][0];  
}  
