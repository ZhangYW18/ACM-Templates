//求出支配点，构建支配树
//除原点连边idom[i]->i
//可近似认为时间复杂度线性
#include <bits/stdc++.h>
using namespace std;
inline int read()
{
	int s = 0; char c; while((c=getchar())<'0'||c>'9');
	do{s=s*10+c-'0';}while((c=getchar())>='0'&&c<='9');
	return s;
}
const int N = 200010;
struct eg{ int dt,nx; }e[N];
int n,m,tim,tot;
int h[N],iw[N],li[N],fa[N],sdom[N],idom[N];
int fo[N],vo[N];
vector<int> pre[N],bkt[N];
int findf(int p)
{
	if(fo[p]==p) return p;
	int r = findf(fo[p]);
	if(sdom[vo[fo[p]]]<sdom[vo[p]]) vo[p] = vo[fo[p]];
	return fo[p] = r;
}
inline int eval(int p)
{ 
	findf(p); 
	return vo[p]; 
}
void dfs(int p)
{
	li[iw[p]=++tim] = p, sdom[p] = iw[p];
	for(int pt=h[p];pt;pt=e[pt].nx) if(!iw[e[pt].dt])
		dfs(e[pt].dt), fa[e[pt].dt] = p;
}
void work()
{
	int i,p;
	dfs(1);
	for(i=tim;i>=2;i--)
	{
		p = li[i];
		for(int k : pre[p]) if(iw[k]) sdom[p] = min(sdom[p],sdom[eval(k)]);
		bkt[li[sdom[p]]].push_back(p);
		int fp = fa[p]; fo[p] = fa[p];
		for(int v : bkt[fp])
		{
			int u = eval(v);
			idom[v] = sdom[u]==sdom[v]?fp:u;
		}
		bkt[fp].clear();
	}
	for(i=2;i<=tim;i++) p = li[i], idom[p] = idom[p]==li[sdom[p]]?idom[p]:idom[idom[p]];
	for(i=2;i<=tim;i++) p = li[i], sdom[p] = li[sdom[p]];
}
inline void link(int a,int b)
{
	e[++tot].dt = b, e[tot].nx = h[a], h[a] = tot;
	pre[b].push_back(a);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	int i;
	n = read(), m = read();
	tim = tot = 0;
	for(i=1;i<=n;i++) h[i] = iw[i] = 0, fo[i] = vo[i] = i, pre[i].clear(), bkt[i].clear();
	for(i=1;i<=m;i++){ int a = read(); link(a,read()); }
	work();
	return 0;
}
