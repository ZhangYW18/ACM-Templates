//带权并查集
int f[maxn],d[maxn];

for (int i=1;i<=n;i++) f[i]=i,d[i]=0;

int find(int x){
    if (f[x]==x) return x;
    int fa=f[x];
    f[x]=find(f[x]);
    d[x]^=d[fa];
    return f[x];
}
//op=0相同，op=1相反
bool join(int x,int y,int op)
{
    int fx=find(x),fy=find(y);
	if (fx==fy) {
		if (d[x]!=d[y]&&op==0) return false;
		if (d[x]==d[y]&&op==1) return false;
		return true;
	}
    f[fy]=fx;
    d[fy]=op^d[x]^d[y];
	return true;
}