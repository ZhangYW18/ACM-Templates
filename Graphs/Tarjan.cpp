int dfn[maxn],low[maxn],color[maxn],val[maxn];
bool inst[maxn];

    mem0(dfn);mem0(low);mem0(color);mem0(inst);mem0(val);
	stack<int> st;
	num=0;
	
void tarjan(int now) {
	num++;
	dfn[now]=low[now]=num;
	inst[now]=1;
	st.push(now);
	for (int i=0;i<v[now].size();i++) {
		int to=v[now][i];
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
		val[cnum]++;
		while (st.top()!=now) {
			color[st.top()]=cnum;
			val[cnum]++;
			inst[st.top()]=0;
			st.pop();
		}
		st.pop();
	}
}
