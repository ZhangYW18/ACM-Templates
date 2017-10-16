ll spfa(int s,int des){
	int i;
    memset(inque,0,sizeof(inque));
    memset(dist,0x3f,sizeof(dist));
	inque[1]=1;
	deque<int> q;
	q.push_back(1);
	dist[1]=0;
	while (!q.empty()) {
		int now=q.front();
		q.pop_front();
		inque[now]=0;
		for (i=head[now];i!=-1;i=edge[i].pre) {
			int to=edge[i].to;
			if (dist[edge[i].from]+edge[i].dist<dist[to]) {
				if (!q.empty()) {
						if (dist[to]<dist[q.front()])  //small label first
					        q.push_front(to);
					    else q.push_back(to);
					} else q.push_back(to);
				dist[to]=dist[edge[i].from]+edge[i].dist;
			}
		}
	}
	return dist[des];
}
