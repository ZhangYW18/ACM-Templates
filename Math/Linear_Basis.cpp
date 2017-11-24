bool linear_basis_insert(ll p) {
	for (int i=maxk;i>=0;i--) {
		if ((p>>i)%2==1) {
			if (!x[i]) {
				x[i]=p;
				for (int j=i-1;j>=0;j--) 
					if (x[j]&&((x[i]>>j)%2==1)) x[i]^=x[j];
                for (int j=i+1;j<=maxk;j++) 
					if ((x[j]>>i)%2==1) x[j]^=x[i];
				return true;
			} else p=p^x[i];
		}
	}
	return p!=0;
}
