//POJ 3764 The xor-longest Path

struct Tree{
	int l,r;
};
Tree tree[maxn*32];
 
void insert(int now,ll val,int depth) {
	if (depth==32) return;
	if ((val>>(31-depth))%2==1) {
		if (tree[now].l==-1) {
			tree[now].l=++num;
			tree[num].l=tree[num].r=-1;
		}	
		insert(tree[now].l,val,depth+1);
	} else {
		if (tree[now].r==-1) {
			tree[now].r=++num;
			tree[num].l=tree[num].r=-1;
		}
		insert(tree[now].r,val,depth+1);
	}
}
 
ll findxor(int now,ll val,int depth) {
	if (depth==32) return 0;
	if ((val>>(31-depth))%2==0) {
		if (tree[now].l!=-1)
		return findxor(tree[now].l,val,depth+1)+(1<<(31-depth));
		else  return findxor(tree[now].r,val,depth+1);
	} else {
		if (tree[now].r!=-1) 
		return findxor(tree[now].r,val,depth+1)+(1<<(31-depth));
		else return findxor(tree[now].l,val,depth+1);
	}
}

