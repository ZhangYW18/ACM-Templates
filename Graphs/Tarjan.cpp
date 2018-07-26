int dfn[maxn],low[maxn],color[maxn];
bool inst[maxn];

    mem0(dfn);mem0(low);mem0(color);mem0(inst);
	stack<int> st;
	num=0;
	
void tarjan(int now) {
	num++;
	dfn[now]=low[now]=num;
	inst[now]=1;
	st.push(now);
	for (int i=head[now];i!=-1;i=edge[i].pre) {
		int to=edge[i].to;
		if (!dfn[to]) {
			tarjan(to);
			low[now]=min(low[now],low[to]);
		}
		else if (inst[to]) 
		    low[now]=min(low[now],dfn[to]); 
	}
	if (dfn[now]==low[now]) {
		inst[now]=0;
		color[now]=++cnum;
		v[cnum].push_back(now);
		while (st.top()!=now) {
			color[st.top()]=cnum;
			inst[st.top()]=0;
			v[cnum].push_back(st.top());
			st.pop();
		}
		st.pop();
	}
}
