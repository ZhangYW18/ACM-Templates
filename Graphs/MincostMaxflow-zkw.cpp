
#include <deque>
//costFlow返回最大流，ans返回费用
bool vis[maxn];
int dist[maxn];
int n,s,t;     //n为总点数，需要初始化
ll ans=0;
int nedge=-1,p[maxk*2],c[maxk*2],cc[maxk*2],nex[maxk*2],head[maxn];
inline void addedge(int x,int y,int z,int zz){
    p[++nedge]=y;c[nedge]=z;cc[nedge]=zz;nex[nedge]=head[x];head[x]=nedge;
}
inline bool spfa(int s,int t){
    for(int i=0;i<=n;i++)dist[i]=1e9,vis[i]=0;
	dist[t]=0;vis[t]=1;
    deque<int>q;q.push_back(t);
    while(!q.empty()){
        int now=q.front();q.pop_front();
        for(int k=head[now];k>-1;k=nex[k])if(c[k^1]&&dist[p[k]]>dist[now]-cc[k]){
            dist[p[k]]=dist[now]-cc[k];
            if(!vis[p[k]]){
                vis[p[k]]=1;
                if(!q.empty()&&dist[p[k]]<dist[q.front()])q.push_front(p[k]);else q.push_back(p[k]);
            }
        }
        vis[now]=0;
    }
    return dist[s]<1e9;
}
inline int dfs(int x,int low){
    if(x==t){vis[t]=1;return low;}
    int used=0,a;vis[x]=1;
    for(int k=head[x];k>-1;k=nex[k])if(!vis[p[k]]&&c[k]&&dist[x]-cc[k]==dist[p[k]]){
        a=dfs(p[k],min(c[k],low-used));
        if(a)ans+=(ll)a*(ll)cc[k],c[k]-=a,c[k^1]+=a,used+=a;
        if(used==low)break;
    }
    return used;
}
inline int costflow(){
    int flow=0;
    while(spfa(s,t)){
        vis[t]=1;
        while(vis[t]){
            memset(vis,0,sizeof vis);
            flow+=dfs(s,1e9);
        }
    }
    return flow;
}

int main() {
	//初始化
	s=0;t=n*2+1;
	ans=0;
	memset(head,-1,sizeof(head));
	memset(nex,-1,sizeof(nex));
	nedge=-1;
}
