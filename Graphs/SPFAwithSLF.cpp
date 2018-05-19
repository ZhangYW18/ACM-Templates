ll spfa(int s,int des){
	int i;
    memset(inque,0,sizeof(inque));
    memset(dist,0x3f,sizeof(dist));
	inque[s]=1;
	que<int> q;
	q.push_back(s);
	dist[s]=0;
	while (!q.empty()) {
		int now=q.front();
		q.pop();
		inque[now]=0;
		for (i=head[now];i!=-1;i=edge[i].pre) {
			int to=edge[i].to;
			if (dist[edge[i].from]+edge[i].dist<dist[to]) {
				q.push_back(to);
				dist[to]=dist[edge[i].from]+edge[i].dist;
			}
		}
	}
	return dist[des];
}
