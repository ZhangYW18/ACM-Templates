sort(edge,edge+num,cmp);

int find (int now) {
	if (f[now]==now) return now; else {
		f[now]=find(f[now]);
		return f[now];
	}
}

int kruskal(int n) {
	int ans=0,cnt=0,i;
	for (i=0;i<=n;i++) f[i]=i;
	for (i=0;i<num;i++) {
		int fa=find(edge[i].from);
		int fb=find(edge[i].to);
		if (fa!=fb) {
			cnt++;
			ans+=edge[i].dist;
			if (cnt==n) return ans;
			f[fa]=fb;
		}
	}
	return 0;
}
