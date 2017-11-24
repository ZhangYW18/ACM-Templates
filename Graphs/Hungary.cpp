//最大匹配匈牙利

bool hungary(int now) {  
    for (int i=head[now];i!=-1;i=edge[i].pre) {  
        int to=edge[i].to;  
        if (!v[to]) {  
            v[to]=1;  
            if (!match[to]||hungary(match[to])) {  
                match[to]=now;match[now]=to;  
                return true;  
            }  
        }  
    }  
    return false;  
}  

    mem0(match);  
    for (i=1;i<=cnt;i++)   
        if (!match[i]) {  
            mem0(v);v[i]=1;  
            if (hungary(i)) sum++;  
        }  
        
