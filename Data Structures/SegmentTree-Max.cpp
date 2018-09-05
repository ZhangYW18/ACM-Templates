num=1;

//可修改线段树区间最值模板
struct Tree {
	int lc,rc,l,r,max,tag;
};
Tree tree[4*maxn];

bool cmp(Tree a,Tree b) {
	if (a.max+a.tag>b.max+b.tag) return true; else return false;
}

void pushup(int now) {
	if (cmp(tree[tree[now].lc],tree[tree[now].rc]))
		tree[now].max=tree[tree[now].lc].max+tree[tree[now].lc].tag;
	 else
		tree[now].max=tree[tree[now].rc].max+tree[tree[now].rc].tag;
}

void pushdown(int now) {
	if (tree[now].tag==0) return;
	tree[tree[now].lc].tag+=tree[now].tag;
	tree[tree[now].rc].tag+=tree[now].tag;
	tree[now].max+=tree[now].tag;
	tree[now].tag=0;
}

//求和的pushdown
void pushdown(int now) {
	if (tree[now].tag==0) return;
	int l=tree[now].lc,r=tree[now].rc;
	tree[l].tag+=tree[now].tag;
	tree[r].tag+=tree[now].tag;
	tree[l].sum+=tree[now].tag*(tree[l].r-tree[l].l+1);
	tree[r].sum+=tree[now].tag*(tree[r].r-tree[r].l+1);
	tree[now].tag=0;
}

void build(int now,int l,int r) {
	tree[now].l=l;
	tree[now].r=r;
	tree[now].tag=0;
	if (l!=r) {
		num++;
		tree[now].lc=num;
		build(num,l,(l+r)/2);
		num++;
		tree[now].rc=num;
		build(num,(l+r)/2+1,r);
		pushup(now);
	} else tree[now].max=dp[l];
}

void update (int now,int l,int r,int c) {
//	cout << now << ' ' << tree[now].l << ' ' << tree[now].r << ' ' << tree[now].max << ' ' << tree[now].tag << endl;
	if (tree[now].l>=l&&tree[now].r<=r) {
		tree[now].tag+=c;         //求和需要同时更新tag和sum
	} else {
		pushdown(now);
		if (l<=(tree[now].l+tree[now].r)/2)
		    update(tree[now].lc,l,r,c);
		if (r>(tree[now].l+tree[now].r)/2)
		    update(tree[now].rc,l,r,c);
		pushup(now);
	}
//	cout << now << ' ' << tree[now].l << ' ' << tree[now].r << ' ' << tree[now].max << ' ' << tree[now].tag << endl;
}

int findmax (int now,int l,int r) {
//	cout << now << ' ' << tree[now].l << ' ' << tree[now].r << ' ' << tree[now].max << ' ' << tree[now].tag << endl;
	if (tree[now].l>=l&&tree[now].r<=r) {
		return tree[now].max+tree[now].tag;
	} else {
		pushdown(now);
		int ans=-inf;
		if (l<=(tree[now].l+tree[now].r)/2)
		    ans=max(ans,findmax(tree[now].lc,l,r));
		if (r>(tree[now].l+tree[now].r)/2)
		    ans=max(ans,findmax(tree[now].rc,l,r));
		return ans;
	}
//	cout << now << ' ' << tree[now].l << ' ' << tree[now].r << ' ' << tree[now].max << ' ' << tree[now].tag << endl;
}





struct Tree {
	int lc,rc,l,r,max,min;
};
Tree tree[4*maxn];

void pushup(int now) {
	tree[now].max=max(tree[tree[now].lc].max,tree[tree[now].rc].max);
	tree[now].min=min(tree[tree[now].lc].min,tree[tree[now].rc].min);
}

void build(int now,int l,int r) {
	tree[now].l=l;
	tree[now].r=r;
	if (l!=r) {
		num++;
		tree[now].lc=num;
		build(num,l,(l+r)/2);
		num++;
		tree[now].rc=num;
		build(num,(l+r)/2+1,r);
		pushup(now);
	} else tree[now].max=tree[now].min=a[l];
}

void update (int now,int pos) {
//	cout << now << ' ' << tree[now].l << ' ' << tree[now].r << ' ' << tree[now].max << ' ' << tree[now].tag << endl;
	if (tree[now].l==tree[now].r&&tree[now].l==pos) {
		tree[now].max=tree[now].min=inf;
	} else {
		if (pos<=(tree[now].l+tree[now].r)/2)
		    update(tree[now].lc,pos);
		if (pos>(tree[now].l+tree[now].r)/2)
		    update(tree[now].rc,pos);
		pushup(now);
	}
//	cout << now << ' ' << tree[now].l << ' ' << tree[now].r << ' ' << tree[now].max << ' ' << tree[now].tag << endl;
}

int findbig(int now,int l,int r,int val) {
	if (tree[now].l==tree[now].r) {
		return tree[now].l;
	} else {
		if (l<=(tree[now].l+tree[now].r)/2&&tree[tree[now].lc].min<=val)
		    return findbig(tree[now].lc,l,r,val);
		if (r>(tree[now].l+tree[now].r)/2&&tree[tree[now].rc].min<=val)
		    return findbig(tree[now].rc,l,r,val);
	}
}

int findmin (int now,int l,int r) {
	if (tree[now].l>=l&&tree[now].r<=r) {
		return tree[now].min;
	} else {
		int ans=inf;
		if (l<=(tree[now].l+tree[now].r)/2)
		    ans=min(ans,findmin(tree[now].lc,l,r));
		if (r>(tree[now].l+tree[now].r)/2)
		    ans=min(ans,findmin(tree[now].rc,l,r));
		return ans;
	}
}
