struct node {
	int id,cnt;ll dist;
	node(int id,int cnt,ll dist):id(id),cnt(cnt),dist(dist) {}
	bool operator <(const node &x)const {
	    return dist>x.dist;
	}
};
priority_queue<node> pq;

void dij(int s,int t) {
	int j,i;
	mem0(visit);
	priority_queue<node> pq;
	meminf(dist);dist[s]=0;meminf(dp);
    for (int i=0;i<=kk;i++) dp[s][i]=0,pq.push(node(s,i,0ll));
	while (!pq.empty()) {
//		if (pq.top().dist>ans) break;    可能优化
        int l=pq.top().cnt,from=pq.top().id;ll dist=pq.top().dist;
        if (visit[from][l]) {
            pq.pop();continue;
        }
        visit[from][l]=1;
        pq.pop();
        for (j=head[from];j!=-1;j=edge[j].pre) {
            int to=edge[j].to;
            if (l!=0) {
                dp[to][l-1]=min(dist,dp[to][l-1]);
                if (!visit[to][l-1]) {
                    pq.push(node(to,l-1,dp[to][l-1]));
                }
            }
            dp[to][l]=min(dp[to][l],dist+edge[j].dist);
            if (!visit[to][l]) {
                pq.push(node(to,l,dp[to][l]));
            }
        }
	}
}
