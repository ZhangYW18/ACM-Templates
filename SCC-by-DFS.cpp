
void dfs1(int now) {
	vis[now]=1;
	int size=v[now].size();
	for (int i=0;i<size;i++) {
		if (!vis[v[now][i]]) dfs1(v[now][i]);
	}
	q[++cnt]=now;
}
 
void dfs2(int now) {
	vis[now]=0;f[now]=c;
	int size=v1[now].size();
	for (int i=0;i<size;i++) {
		if (vis[v1[now][i]]) dfs2(v1[now][i]);
	}
}
