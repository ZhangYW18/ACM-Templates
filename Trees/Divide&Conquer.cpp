
int head[maxn],size[maxn],ms[maxn];
int num=0,root=-1,rs=inf,sum;
bool visit[maxn];

struct Edge {
	int from,to,pre;
};
Edge edge[maxn*2];

void addedge(int from, int to) {
	edge[num]=(Edge){from,to,head[from]};
	head[from]=num++;
	edge[num]=(Edge){to,from,head[to]};
	head[to]=num++;
}

void getroot(int now,int fa) {
	size[now]=ms[now]=0;
	for (int i=head[now];i!=-1;i=edge[i].pre) {
		int to=edge[i].to;
		if (!visit[to]&&to!=fa) {
			getroot(to,now);
			size[now]+=size[to];
			ms[now]=max(ms[now],size[to]);
		}
	}
	size[now]++;
	ms[now]=max(ms[now],sum-size[now]);
	if (ms[now]<rs) root=now,rs=ms[now];
}

void dfs(int now,int fa,int val,int sta) {
//	cnt[sta^=(1<<(s[now]-'a'))]+=val;
	for (int i=head[now];i!=-1;i=edge[i].pre) {
		int to=edge[i].to;
		if (!visit[to]&&to!=fa) dfs(to,now,val,sta); 
	} 
}

ll cal(int now,int fa,int sta) {
	sta^=(1<<(s[now]-'a'));
//	ll ssum=cnt[sta];
//	for (int i=0;i<20;i++) 
//		ssum+=cnt[sta^(1<<i)];
	for (int i=head[now];i!=-1;i=edge[i].pre) {
		int to=edge[i].to;
		if (!visit[to]&&to!=fa) ssum+=cal(to,now,sta); 
	} 
	ans[now]+=ssum;
	return ssum;
}

void solve(int now) {
	visit[now]=1;
	dfs(now,0,1,0); 
	//计算当前节点开头的路径数 
	ll ssum=cnt[0];
	for (int i=0;i<20;i++) 
		ssum+=cnt[1<<i];
	//计算当前节点所有儿子分支与其他分支的贡献 
	for (int i=head[now];i!=-1;i=edge[i].pre) {
		int to=edge[i].to;
		if (!visit[to]) {
			dfs(to,now,-1,1<<(s[now]-'a'));     //去掉当前分支的影响
			ssum+=cal(to,now,0); 
			dfs(to,now,1,1<<(s[now]-'a'));
		}
	}
	ans[now]+=ssum/2;   //每条路径正反各被算了一次 
	//先去掉当前点的影响，再dfs访问没有处理的点
	dfs(now,0,-1,0); 
	for (int i=head[now];i!=-1;i=edge[i].pre) {
		int to=edge[i].to;
		if (!visit[to]) {
			root=-1,rs=inf;
			sum=size[to];
			getroot(to,0);
			solve(root);
		}
	}
}
