struct node{
	struct node *fail;
	struct node *next[maxk];
	int cnt,id;
	void init() {
		fail=NULL;
		for (int i=0;i<maxk;i++) next[i]=NULL;
		cnt=0;
		id=++num;
	}
};
node *a[maxn],*q[maxn];

void insert(string s,node *root,int len) {
	node *now=root;
	int i;
	for (i=0;i<len;i++) {
		int pos=id[s[i]];
		if (now->next[pos]==NULL) {
	    	now->next[pos]=new node;
	    	now->next[pos]->init();
	    	a[num]=now->next[pos];
    	}
    	now=now->next[pos];
	}
	now->cnt++;
}

void buildfail(node *root) {
	node *p=root;
	int front=0,tail=0,i;
	for (i=0;i<maxk;i++) {
		if (p->next[i]!=NULL) {
			p->next[i]->fail=root;
			q[tail++]=p->next[i];
		} else p->next[i]=root;
	}
	while (front<tail) {
		p=q[front];
		for (i=0;i<maxk;i++) {
			if (p->next[i]==NULL) 
			    p->next[i]=p->fail->next[i];
			else {
				node *x=p->fail;
				while (x!=NULL) {
					if (x->next[i]!=NULL) {
						p->next[i]->fail=x->next[i];
						break;
					}
					x=x->fail;
				}
				if (p->fail->next[i]->cnt) p->next[i]->cnt++;
				q[tail++]=p->next[i];
			}
		}
		front++;
	}
}
