//无指针版
int q[maxn];
int num;

struct node{
	int fail,next[maxk]; 
	int cnt,len;
	void init() {
		fail=-1;
		for (int i=0;i<maxk;i++) next[i]=-1;
		cnt=len=0;
	}
};
node a[maxn];

void insert(string s,int root,int len) {
	int now=root;
	int i;
	for (i=0;i<len;i++) {
		int pos=s[i]-'a';
		if (a[now].next[pos]==-1) {
	    	a[now].next[pos]=++num;
	    	a[num].init();
    	}
    	now=a[now].next[pos];
	}
	a[now].cnt++;
}
//不补全trie图
void buildfail(int root) {
    int p=root;
    int front=0,tail=0,i;
    for (i=0;i<maxk;i++) {
        if (a[p].next[i]!=-1) {
            a[a[p].next[i]].fail=root;
            q[tail++]=a[p].next[i];
        } else a[p].next[i]=root;
    }
    while (front<tail) {
        p=q[front];
        for (i=0;i<maxk;i++) {
            if (a[p].next[i]==-1) 
                a[p].next[i]=a[a[p].fail].next[i];
            else {
                a[a[p].next[i]].fail=a[a[p].fail].next[i];
                q[tail++]=a[p].next[i];
            }
        }
        front++;
    }
}
//补全trie图
void buildfail(int root) {
	int p=root;
	int front=0,tail=0,i;
	for (i=0;i<maxk;i++) {
		if (a[p].next[i]!=-1) {
			a[a[p].next[i]].fail=root;
			q[tail++]=a[p].next[i];
		} else a[p].next[i]=root;
	}
	while (front<tail) {
		p=q[front];
		for (i=0;i<maxk;i++) {
			if (a[p].next[i]==-1) 
			    a[p].next[i]=a[a[p].fail].next[i];
			else {
				int x=a[p].fail;
				while (x!=-1) {
					if (a[x].next[i]!=-1) {
						a[a[p].next[i]].fail=a[x].next[i];
						break;
					}
					x=a[x].fail;
				}
				if (a[a[a[p].fail].next[i]].cnt) a[a[p].next[i]].cnt++;
				q[tail++]=a[p].next[i];
			}
		}
		front++;
	}
}

void search(string s,int root,int len) {  
    int k=0,i;  
    int p=root,now;  
    for (i=0;i<len;i++) {
        p=a[p].next[s[i]-'a'];  
        now=p;  
        while (now!=root&&a[now].cnt!=-1) {  
            if (a[now].cnt) {
            	Successful Match!
            }
            now=a[now].fail;  
        }
    }
}  
