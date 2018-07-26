struct node {
	int id;ll dist;
	node(int id,ll dist):id(id),dist(dist) {}
	bool operator <(const node &x)const {
	    return dist>x.dist;
	}
};
priority_queue<node> pq;

ll dij(int n,int s,int t) {
	int j,i;
	mem0(visit);
	priority_queue<node> pq;
	visit[s]=1;
	for (j=head[s];j!=-1;j=edge[j].pre) 
		pq.push(node(j,edge[j].dist));
	meminf(dist);dist[s]=0;
	for (int k=1;k<n;k++) {
//		if (pq.top().dist>ans) break;    可能优化
		while (visit[edge[pq.top().id].to]&&!pq.empty()) pq.pop();
		if (pq.empty()) break;
		i=pq.top().id;
		int to=edge[i].to;
		if (visit[to]) continue;
		visit[to]=1;
		dist[to]=pq.top().dist;
		pq.pop();
		for (j=head[to];j!=-1;j=edge[j].pre) 
			if (!visit[edge[j].to]) 
				pq.push(node(j,dist[to]+edge[j].dist));
	}
	return dist[t];
}
