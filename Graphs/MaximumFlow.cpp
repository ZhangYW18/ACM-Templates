/*求有上下界、有源汇的可行流的方法：新添加新的源点和汇点，统计每个点流入和流出的量，流入多则连源点，流出多则连汇点，流量为多出的流。
原图当中的边，每条边的流量变为流量上界减去下界。对于原来的源点汇点，添加边(t,s,inf)，以平衡流量。
最后跑最大流，如果新源点出发的所有边都满流，则存在可行流。   */

//dinic算法
//s为原点,n为汇点
int head[maxn],current[maxn],dist[maxn];

struct Edge {  
    int from,to,flow,pre;  
};  
Edge edge[maxk*2];  
  
void addedge(int from,int to,int flow) {  
    edge[num]=(Edge){from,to,flow,head[from]};  
    head[from]=num++;  
    edge[num]=(Edge){to,from,0,head[to]};  
    head[to]=num++;  
}  
  
bool bfs (int s,int n) {  
    queue<int> q;  
    q.push(s);  
    memset(dist,-1,sizeof(dist));  
    dist[s]=0;  
    while (!q.empty()) {  
        int now=q.front();  
        q.pop();  
        for (int i=head[now];i!=-1;i=edge[i].pre) {  
            int to=edge[i].to;  
            if (dist[to]==-1&&edge[i].flow>0) {  
                dist[to]=dist[now]+1;  
                q.push(to);  
            }  
        }  
    }  
    return dist[n]!=-1;  
}  
  
int dfs(int now,int flow,int n) {  
    int f;  
    if (now==n) return flow;  
    for (int i=current[now];i!=-1;i=edge[i].pre) {  
        int to=edge[i].to;  
        current[now]=i;  
        if (dist[now]+1==dist[to]&&edge[i].flow>0&&(f=dfs(to,min(flow,edge[i].flow),n))) {  
            edge[i].flow-=f;  
            edge[i^1].flow+=f;  
            return f;  
        }  
    }  
    return 0;  
}  
  
int dinic(int s,int n) {  
    int sum=0,f;  
    while (bfs(s,n)) {  
        memcpy(current,head,sizeof(head));  
        while (f=dfs(s,inf,n)) sum+=f;  
    }  
    return sum;  
}  

