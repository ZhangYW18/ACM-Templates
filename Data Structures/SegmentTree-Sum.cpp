
num=1;

struct Tree {
	int lc,rc,l,r,sum,tag;
};
Tree tree[4*maxn];

void build(int now,int l,int r,int c) {
	tree[now].l=l;
	tree[now].r=r;
	tree[now].tag=-1;
	if (l!=r) {
		num++;
		tree[now].lc=num;
		build(num,l,(l+r)/2,c);
		num++;
		tree[now].rc=num;
		build(num,(l+r)/2+1,r,c);
		tree[now].sum=tree[tree[now].lc].sum+tree[tree[now].rc].sum;
	} else tree[now].sum=a[l]>=c?1:0;
}

void pushdown(int now) {
	if (tree[now].tag==-1) return;
	int l=tree[now].lc,r=tree[now].rc;
	tree[l].tag=tree[now].tag;
	tree[r].tag=tree[now].tag;
	tree[l].sum=tree[now].tag*(tree[l].r-tree[l].l+1);
	tree[r].sum=tree[now].tag*(tree[r].r-tree[r].l+1);
	tree[now].tag=-1;
}

void update (int now,int l,int r,int c) {
//	cout << now << ' ' << tree[now].l << ' ' << tree[now].r << ' ' << tree[now].sum << ' ' << tree[now].tag << endl;
	if (tree[now].l>=l&&tree[now].r<=r) {
		tree[now].sum=c*(tree[now].r-tree[now].l+1);
		tree[now].tag=c; 
	} else {
		pushdown(now);
		if (l<=(tree[now].l+tree[now].r)/2) 
		    update(tree[now].lc,l,r,c);
		if (r>(tree[now].l+tree[now].r)/2)
		    update(tree[now].rc,l,r,c);
		tree[now].sum=tree[tree[now].lc].sum+tree[tree[now].rc].sum;
	}
//	cout << now << ' ' << tree[now].l << ' ' << tree[now].r << ' ' << tree[now].sum << ' ' << tree[now].tag << endl;
}

int findsum(int now,int l,int r) {
//	cout << now << ' ' << tree[now].l << ' ' << tree[now].r << ' ' << tree[now].sum << ' ' << tree[now].tag << endl;
	pushdown(now);
	if (tree[now].l>=l&&tree[now].r<=r) {
		return tree[now].sum;
	} else {
		int f=0;
		if (l<=(tree[now].l+tree[now].r)/2) 
		    f=findsum(tree[now].lc,l,r);
		if (r>(tree[now].l+tree[now].r)/2)
		    f+=findsum(tree[now].rc,l,r);
		return f;
	}
}
