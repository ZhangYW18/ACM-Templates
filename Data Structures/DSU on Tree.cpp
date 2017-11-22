int dfs2(int now) {  
    visit[now]=1;son[now]=-1;size[now]=1;  
    for (int i=head[now];i!=-1;i=edge[i].pre) {  
        int to=edge[i].to;  
        if (!visit[to]) {  
            size[now]+=dfs2(to);  
            if (son[now]==-1||size[to]>size[son[now]]) son[now]=to;  
        }  
    }
    if (son[now]!=-1) big[son[now]]=1;
    return size[now];
}  

void add(int now,int fa,int val) {
	cnt[c[now]]+=val;
	if (cnt[c[now]]>mx) {
		mx=cnt[c[now]];sum=c[now];
	} else if (cnt[c[now]]==mx) 
		sum+=(ll)c[now];
	for (int i=head[now];i!=-1;i=edge[i].pre) {
		int to=edge[i].to;
		if (to!=fa&&!big[to]) add(to,now,val);
	}
}

void dfs(int now,int fa,bool rem) {
	visit[now]=1;
	for (int i=head[now];i!=-1;i=edge[i].pre) {
		int to=edge[i].to;
		if (to!=fa&&!big[to]) dfs(to,now,0);
	}
	if (son[now]!=-1) dfs(son[now],now,1);
	add(now,fa,1);
	ans[now]=sum;
	if (son[now]!=-1) big[son[now]]=0;
	if (!rem) add(now,fa,-1),sum=mx=0;
}
