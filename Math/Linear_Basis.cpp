bool linear_basis_insert(ll p) {
	for (int i=maxk;i>=0;i--) {
		if ((p>>i)%2==1) {
			if (!x[i]) {
				x[i]=p;
				return true;
			} else p=p^x[i];
		}
	}
	return p!=0;
}
