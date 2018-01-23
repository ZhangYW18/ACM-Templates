//KMP

void buildnext(char s[]) {
	int len=strlen(s);
	int j=0;
	next[0]=next[1]=0;
	for (int i=1;i<len;i++) {
		while (j>0&&s[i]!=s[j])
		    j=next[j];
		if (s[i]==s[j]) j++;
		next[i+1]=j;
	}
}

	j=0;
	for (i=0;i<lens;i++) {
	    	while (j>0&&k[j]!=s[i]) 
	     	   j=next[j];
	   	 if (k[j]==s[i]) j++;
	   	 if (j==lenk) {
			ans++;k=next[j];
		 }
	}
