struct node {
	int id; ll dist;
	node(int id,int dist):id(id),dist(dist) {}
	bool operator <(const node &x)const {
	    return dist>x.dist;
	}
};

void dij(int n) {
	mem0(visit);
	priority_queue<node> pq;
	meminf(dist);dist[1]=0;
    pq.push(node(1,0));
	while (!pq.empty()) {
//		if (pq.top().dist>ans) break;    可能优化
        int now=pq.top().id;
        if (visit[now]) {
            pq.pop();continue;
        }
        dist[now]=pq.top().dist;
        visit[now]=1;
        pq.pop();
        for (int i=head[now];i!=-1;i=edge[i].pre) {
			int to=edge[i].to;
            if (!visit[to]) {
                pq.push(node(j,dist[now]+edge[i].dist));
            }
        }
    }
}
