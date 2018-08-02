
meminf(d);

void floyd(int n) {
	for (int i=1;i<=n;i++) 
		for (int j=1;j<=n;j++) {
			if (i==j) continue;
			for (int k=1;k<=n;k++) {
				if (i==k||j==k) continue;
				d[j][k]=min(d[j][k],d[j][i]+d[i][k]);
			}
		}
}