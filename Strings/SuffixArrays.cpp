//后缀数组

int wa[maxn],wb[maxn],wv[maxn],ws[maxn],sa[maxn],ranki[maxn],height[maxn];
int s[maxn],a[maxn];

int cmp(int *r,int a,int b,int l) {
	return r[a]==r[b]&&r[a+l]==r[b+l];
}

void build(int *r,int *sa,int n,int m) {
	int i,j,k,p,*x=wa,*y=wb,*t;
	
	for (i=0;i<m;i++) ws[i]=0;
	for (i=0;i<n;i++) ws[x[i]=r[i]]++;
	for (i=0;i<m;i++) ws[i]+=ws[i-1];
	for (i=n-1;i>=0;i--) 
	    sa[--ws[x[i]]]=i;
	//sa[i]表示排名第i位的后缀的起始位置 
	for (j=1,p=1;p<n;j*=2,m=p) {
		for (p=0,i=n-j;i<n;i++) 
		    y[p++]=i;
		for (i=0;i<n;i++) 
		    if (sa[i]>=j) y[p++]=sa[i]-j;
		// w[i]表示第二关键字排名第i位的位置 
		for (i=0;i<n;i++) 
		    wv[i]=x[y[i]];
		for (i=0;i<m;i++) ws[i]=0;
		for (i=0;i<n;i++) 
		    ws[wv[i]]++;
		for (i=1;i<m;i++) ws[i]+=ws[i-1];
		for (i=n-1;i>=0;i--) 
		    sa[--ws[wv[i]]]=y[i];
		
		t=x;x=y;y=t;
		p=1;x[sa[0]]=0;
		for (i=1;i<n;i++) 
		    x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
		//前后两个排名相近的字符串是否完全相同
		//x[]记录排名 
	}
	//height下标从1开始！ 
	for (i=1;i<n;i++) ranki[sa[i]]=i;
	k=0; 
	for (i=0;i<n-1;height[ranki[i++]]=k) {
		if (k) k--;
		for (j=sa[ranki[i]-1];r[i+k]==r[j+k];k++);
	}
}

void rmq(int n) {
	int i,j;
	for (i=1;i<=n;i++) mn[i][0]=height[i];
	for (j=1;(1<<j)<=n;j++) {
		for (i=1;i+(1<<j)-1<=n;i++) {
			mn[i][j]=min(mn[i][j-1],mn[i+(1<<(j-1))][j-1]);
		}
	}
}

int lcp(int a,int b) {
	int fa=ranki[a],fb=ranki[b];
	if (fa>fb) swap(fa,fb);
	fa++;
	int k=0;
	while ((1<<(k+1))<=(fb-fa+1)) k++;
	return min(mn[fa][k],mn[fb-(1<<k)+1][k]);
}
