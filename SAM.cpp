#include <cstdio>
#include <iostream>
#include <string.h>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
const int maxn=100005,maxk=26,inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;

class SAM {  
    public:  
    void init() {  
        num=last=0;  
        a[0].len=0;a[0].fa=-1;  
        for (int i=0;i<maxk;i++) a[0].son[i]=-1;  
    }  
    void update (int c) {  
        int now=++num,p;  
        a[now].len=a[last].len+1;  
        memset(a[now].son,-1,sizeof(a[now].son));  
        for (p=last;p!=-1&&a[p].son[c]==-1;p=a[p].fa)  
            a[p].son[c]=now;  
        if (p==-1) a[now].fa=0; else {  
            int q=a[p].son[c];  
            if (a[p].len+1==a[q].len) {  
                a[now].fa=q;  
            } else {  
                int ne=++num;  
                a[ne].len=a[p].len+1;  
                memcpy(a[ne].son,a[q].son,sizeof(a[q].son));  
                a[ne].fa=a[q].fa;  
                for (;p!=-1&&a[p].son[c]==q;p=a[p].fa)   
                    a[p].son[c]=ne;  
                a[q].fa=a[now].fa=ne;  
            }  
        }  
        last=now;  
    }  
    int getfa(int n) {
    	return a[n].fa;
    }
    int getlen(int n) {
    	return a[n].len;
    }
    int getnum() {
    	return num;
    }
    int getson(int n,int c) {
    	return a[n].son[c];
    }
    private:  
    int num,last;  
    struct node{  
        int len,fa;  
        int son[maxk];  
    } a[maxn*2];  
};  
SAM sa;  

int w[maxn*2],r[maxn*2];
void topsort() {
    int m=sa.getnum(),i;
    mem0(w);
    for(i=0;i<=m;i++) w[sa.getlen(i)]++;  
    for(i=0;i<=len;i++) w[i]+=w[i-1];  
    for(i=m;i>=0;i--) r[--w[sa.getlen(i)]]=i;  
    int now=0; 
    for (i=0;i<len;i++) {
	now=sa.getson(now,s[i]-'a');
	dp[now]++;
    }
    for (i=m;i>0;i--) {
    	int to=sa.getfa(r[i]);
    	if (to!=-1) dp[to]+=dp[r[i]]; 
    }
}
	
int main() {
	
	return 0;
}
