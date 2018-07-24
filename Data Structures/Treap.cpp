//Treap支持在logn时间内完成插入、删除、询问排名、询问第k大数、询问前驱、询问后继、区间加减的操作
//无旋Treap支持Split/Merge操作
#include<iostream>
#include<cstdio>
#include<algorithm>
#define INF 100000007
#define P1 39916801
#define P2 4987657
using namespace std;

typedef long long ll;
const int N = 100005;
struct node{
    int v,rnd,size;
    node *ch[2],*pa;       
}pool[N];
int cnt;

int rr;
int Getrnd(){  //生成随机数
    rr=((ll)rr*P1)%P2;
    return rr;    
}

struct treap{
    node *root,*rf;
    int size(node *p){
        return p?p->size:0;    
    }
    void update(node *p){
        p->size=size(p->ch[0])+size(p->ch[1])+1;     
    }
    void rotate(node *p,int t){
        node *son=p->ch[!t],*pa=p->pa,*gp=p->pa->pa;
        pa->ch[t]=son;
        if(son) son->pa=pa;
        p->ch[!t]=pa;
        pa->pa=p;
        p->pa=gp;
        gp->ch[pa==gp->ch[1]]=p;
        if(root==pa) root=p;
        update(pa);update(p); 
    }
    void insert(node *p,node *nd){
        int f=p->v<nd->v?1:0;
        if(!p->ch[f]){
            p->ch[f]=nd;
            nd->pa=p;              
        }
        else insert(p->ch[f],nd);
        update(p);
        if(p->ch[f]->rnd>p->rnd) rotate(p->ch[f],f);
    }
    void Ins(int v){
        node *nd=&pool[++cnt];
        nd->v=v;nd->size=1;nd->rnd=Getrnd();
        nd->pa=nd->ch[0]=nd->ch[1]=NULL;
        if(root) insert(root,nd);
        else{
            root=nd;
            root->pa=rf;
            rf->ch[1]=root;
        }
    }
    void del(node *p,int v){ //删除 注意向上更新处容易写错
        if(p->v==v){
            if(!p->ch[0] || !p->ch[1]){
                node *pa=p->pa,*son=p->ch[p->ch[0]?0:1];
                pa->ch[p==pa->ch[1]]=son;
                if(son) son->pa=pa;
                if(p==root) root=son;
                while(pa)
                    update(pa),pa=pa->pa;
            }
            else{
                int f=p->ch[1]->rnd>p->ch[0]->rnd?1:0;
                rotate(p->ch[f],f);del(p,v);
            }
        }
        else del(p->ch[v>p->v],v);
    }
    int rank(node *p,int v){ //比v小的节点个数
        if(!p) return 0;
        if(p->v<v) return 1+size(p->ch[0])+rank(p->ch[1],v);
        else return rank(p->ch[0],v);
    }
    int find(node *p,int k){ //询问排名第k的节点值
        if(size(p->ch[0])>=k) return find(p->ch[0],k);
        if(size(p->ch[0])==k-1) return p->v;
        return find(p->ch[1],k-size(p->ch[0])-1);
    }
    int pre(node *p,int v){//前驱
        if(!p) return -INF;
        if(v>p->v) return max(p->v,pre(p->ch[1],v));
        else return pre(p->ch[0],v);
    }
    int sub(node *p,int v){//后继
        if(!p) return INF;
        if(v<p->v) return min(p->v,sub(p->ch[0],v));
        else return sub(p->ch[1],v);
    }
    void inorder(node *p){
        if(p->ch[0]) inorder(p->ch[0]);
        printf("%d ",p->v);
        if(p->ch[1]) inorder(p->ch[1]);     
    }
}tr;

int main()
{
    int n,opt,x;
    scanf("%d",&n);
    
    tr.rf=&pool[++cnt];
    while(n--){
        scanf("%d%d",&opt,&x);
        switch(opt){
            case 1:tr.Ins(x);break;//插入
            case 2:tr.del(tr.root,x);break;//删除
            case 3:printf("%d\n",tr.rank(tr.root,x)+1);break;//某数排名=比该数小的个数+1
            case 4:printf("%d\n",tr.find(tr.root,x));break;//排名x的数
            case 5:printf("%d\n",tr.pre(tr.root,x));break;//前驱
            case 6:printf("%d\n",tr.sub(tr.root,x));break;//后继
            default:break;
        }
    }
    
    return 0;
}
