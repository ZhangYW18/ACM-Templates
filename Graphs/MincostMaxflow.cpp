//spfa实现最小费用最大流
int head[maxn],dist[maxn],path[maxn],rflow[maxn];
bool inque[maxn];
int num=0;
num=0;memset(head,-1,sizeof(head));

struct Edge {  
    int from,to,cost,flow,pre;  
};  
Edge edge[maxk*2];  
  
void addedge(int s,int t,int cost,int flow) {  
    edge[num]=(Edge){s,t,cost,flow,head[s]};  
    head[s]=num++;  
    edge[num]=(Edge){t,s,-cost,0,head[t]};  
    head[t]=num++;  
}  
  
int spfa(int s,int t) {  
    mem0(inque);meminf(dist);  
    memset(path,-1,sizeof(path));  
    memset(rflow,-1,sizeof(rflow));  
    queue<int> q;  
    q.push(s);  
    inque[s]=1;  
    int i;  
    dist[s]=0;  
    rflow[s]=inf;  
    while (!q.empty()) {  
        int now=q.front();  
        q.pop();  
        inque[now]=0;  
        for (i=head[now];i!=-1;i=edge[i].pre) {  
            int to=edge[i].to;  
            if (edge[i].flow>0&&dist[now]+edge[i].cost<dist[to]) {  
                dist[to]=dist[now]+edge[i].cost;  
                path[to]=i;  
                rflow[to]=min(rflow[now],edge[i].flow);  
                if (!inque[to]) {  
                    inque[to]=1;  
                    q.push(to);  
                }  
            }  
        }  
    }  
    if (dist[t]==inf) return 0; else return dist[t];  
}  
  
int mincostmaxflow(int s,int t) {  
    int f,sum=0,now;  
    while (f=spfa(s,t)) {  
        now=path[t];  
        while (now!=-1) {  
//          int i=now;  
//          cout << edge[i].from << ' ' << edge[i].to << ' ' << edge[i].cost << ' ' << edge[i].flow << ' ' << endl;     
            edge[now].flow-=rflow[t];  
            edge[now^1].flow+=rflow[t];  
            now=path[edge[now].from];  
//          cout << edge[i].from << ' ' << edge[i].to << ' ' << edge[i].cost << ' ' << edge[i].flow << ' ' << endl;  
        }  
        sum+=f*rflow[t];  
    }  
    return sum;  
}  
