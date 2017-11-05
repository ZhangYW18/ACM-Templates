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
Edge edge[maxk];

void addedge(int f,int t,int d) {
	edge[num].from=f;edge[num].to=t;edge[num].dist=d;
	edge[num].pre=head[f];head[f]=num++;
	edge[num].from=t;edge[num].to=f;edge[num].dist=d;
	edge[num].pre=head[t];head[t]=num++;
}

int dj(int s,int t) {
	int j,i;
	mem0(mark);mem0(visit);
	priority_queue<node> pq;
	visit[s]=1;
	for (j=head[s];j!=-1;j=edge[j].pre) {
		pq.push(node(j,edge[j].dist));
		mark[j]=mark[j^1]=1;
	}
	meminf(dist);dist[s]=0;
	while (!pq.empty()) {
		if (pq.top().dist>ans) break;
		i=pq.top().id;
		if (visit[edge[i].to]) continue;
		visit[to]=1;
		pq.pop();
		dist[to]=edge[i].dist+dist[edge[i].from];
		for (j=head[to];j!=-1;j=edge[j].pre) 
			if (!visit[edge[j].to]&&!mark[j]) 
				pq.push(node(j,dist[to]+edge[j].dist));
				mark[j]=mark[j^1]=1;
			}
	}
	return dist[t];
}
