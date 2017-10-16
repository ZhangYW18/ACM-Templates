//dfs序+RMQ实现LCA
int head[maxn],a[maxn*2],mind[maxn*2][20],f[maxn],d[maxn],dep[maxn*2];
bool visit[maxn];
int dfn,num;

void dfs(int now,int step) {
	visit[now]=1;a[++dfn]=now;f[now]=dfn;dep[dfn]=step;
	for (int i=head[now];i!=-1;i=edge[i].pre) {
		int to=edge[i].to;
		if (!visit[to]) {
			d[to]=d[now]+1;
			dfs(to,step+1);
			a[++dfn]=now;
			dep[dfn]=step;
		}
	}
}

void init(int n) {
	int i,j;
	for (i=1;i<=n;i++) mind[i][0]=i;
	for (j=1;(1<<j)<=n;j++) {
		for (i=1;i+(1<<j)-1<=n;i++) {
			int p=mind[i][j-1],q=mind[i+(1<<(j-1))][j-1];
			mind[i][j]=dep[p]<dep[q]?p:q;
		}
	}
}
//注意：查询x,y的LCA时应为find(f[x],f[y])
int find(int l,int r) {
	int k=0;
	if (l>r) {
		int p=l;l=r;r=p;
	}
	while (1<<(k+1)<=(r-l+1)) k++;
	int p=mind[l][k],q=mind[r-(1<<k)+1][k];
	return dep[p]<dep[q]?a[p]:a[q];
}
