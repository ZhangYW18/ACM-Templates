bool dfs(int now) {  
    if (color[now]==2) return false;  
    if (color[now]==1) return true;  
    color[now]=1;  
    color[now^1]=2;  
    dfn[++num]=now;  
    int size=v[now].size();  
    for (int i=0;i<size;i++) {  
        int to=v[now][i];  
        if (!dfs(to)) return false;  
    }  
    return true;  
}  

        memset(color,0,sizeof(color));  
        int flag=1;  
        for (i=0;i<n;i++) {  
            if (!color[i*2]) {  
                num=0;  
                if (!dfs(i*2)) {  
                    for (j=1;j<=num;j++)   
                        color[dfn[j]]=color[dfn[j]^1]=0;  
                    if (!dfs(i*2+1)) {  
                        flag=0;  
                        break;  
                    }  
                }  
            }  
        }  
