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

int dj(int k) {
	int ans=inf,j,i;
	mem0(mark);
	meminf(dist);
	while (!pq.empty()) {
		i=pq.top().id;
		int from,to;
		from=edge[i].from;
		to=edge[i].to;
		pq.pop();
		if (edge[i].dist+dist[from]<dist[to]) {
			dist[to]=edge[i].dist+dist[from];
				for (j=head[to];j!=-1;j=edge[j].pre) {
		        	if (!mark[j]) {
		        		if (edge[j].from==to)
						    pq.push(node(j,edge[j].dist+dist[to]));
				        else 
						    pq.push(node(j^1,edge[j].dist+dist[to]));
		            	mark[j]=mark[j^1]=1;
		         	}
	        	}
		}
	}
	return dist[0];
}
