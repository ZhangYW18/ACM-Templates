//Dijkstra

struct node {
	int id,dist;
	node(int id,int dist):id(id),dist(dist) {}
	bool operator <(const node &x)const {
	    return dist>x.dist;
	}
};
priority_queue<node> pq;
struct Edge {
	int from,to,dist,pre;
};
Edge edge[maxk*2];

void addedge(int f,int t,int d) {
	edge[num].from=f;edge[num].to=t;edge[num].dist=d;
	edge[num].pre=head[f];head[f]=num++;
	edge[num].from=t;edge[num].to=f;edge[num].dist=d;
	edge[num].pre=head[t];head[t]=num++;
}

int dj(int n,int s,int t) {
	int j,i;
	mem0(visit);
	priority_queue<node> pq;
	visit[s]=1;
	for (j=head[s];j!=-1;j=edge[j].pre) 
		pq.push(node(j,edge[j].dist));
	meminf(dist);dist[s]=0;
	for (int k=1;k<n;k++) {
		if (pq.top().dist>ans) break;
		i=pq.top().id;
		int to=edge[i].to;
		if (visit[to]) continue;
		visit[to]=1;
		dist[to]=pq.top().dist;
		pq.pop();
		for (j=head[to];j!=-1;j=edge[j].pre) 
			if (!visit[edge[j].to]&&dist[to]+edge[j].dist<ans) 
				pq.push(node(j,dist[to]+edge[j].dist));
	}
	return dist[t];
}
