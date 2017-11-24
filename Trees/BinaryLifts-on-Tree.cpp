void dfs(int now,int step) {  
    visit[now]=1;dep[now]=step;  
    for (int i=0;i<v[now].size();i++) {  
        int to=v[now][i];  
        if (!visit[to]) {  
            fa[to][0]=now;mxlen[to][0]=d[now][i];  
            dfs(to,step+1);  
        }  
    }  
}  
  
int getmaxlen(int x,int y) {  
    if (dep[x]<dep[y]) swap(x,y);  
    int i,ans=-inf;  
    for (i=18;i>=0;i--) {  
        if (dep[fa[x][i]]>=dep[y]) {  
            ans=max(ans,mxlen[x][i]);  
            x=fa[x][i];   
        }  
    }  
    if (x==y) return ans;  
    for (i=18;i>=0;i--) {  
        if (fa[x][i]!=fa[y][i]) {  
            ans=max(ans,max(mxlen[x][i],mxlen[y][i]));  
            x=fa[x][i];y=fa[y][i];  
        }  
    }  
    ans=max(ans,max(mxlen[x][0],mxlen[y][0]));  
    return ans;  
}  
  
void update(int x,int y,int val) {  
    if (dep[x]<dep[y]) swap(x,y);  
    int i;  
    for (i=18;i>=0;i--) {  
        if (dep[fa[x][i]]>=dep[y]) {  
            mnlen[x][i]=min(val,mnlen[x][i]);  
            x=fa[x][i];   
        }  
    }  
    if (x==y) return;  
    for (i=18;i>=0;i--) {  
        if (fa[x][i]!=fa[y][i]) {  
            mnlen[x][i]=min(mnlen[x][i],val);  
            mnlen[y][i]=min(mnlen[y][i],val);  
            x=fa[x][i];y=fa[y][i];  
        }  
    }  
    mnlen[x][0]=min(mnlen[x][0],val);  
    mnlen[y][0]=min(mnlen[y][0],val);  
}  
