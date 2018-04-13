struct complex
{
	double r, i;
	complex(double _r = 0, double _i = 0)
	{
		r = _r; i = _i;
	}
	complex operator +(const complex &b)
	{
		return complex(r + b.r, i + b.i);
	}
	complex operator -(const complex &b)
	{
		return complex(r - b.r, i - b.i);
	}
	complex operator *(const complex &b)
	{
		return complex(r*b.r - i * b.i, r*b.i + i * b.r);
	}
};
complex conj(complex a) {
	return complex(a.r, -a.i);
}
complex a[maxn*2], b[maxn*2];
int ans[maxn*2];

struct fff {
	int n, rev[maxn*2];
	complex o[maxn*2], oi[maxn*2];

	void init(int m) {
		n = 1; 
		int k = 0;
		mem0(rev); mem0(o); mem0(oi);
		while (n < m) n <<= 1, k++;
		for (int i = 0; i < n; i++) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (k - 1));
		for (k = 0; k < n; k++) {
			o[k] = complex(cos(2 * pi / n * k), sin(2 * pi / n * k));
			oi[k] = conj(o[k]);
		}
	}

	void fft(complex *a, complex *w) {
		for (int i = 0; i < n; i++)
			if (i < rev[i]) swap(a[i], a[rev[i]]);
		for (int l = 2; l <= n; l <<= 1) {
			int m = l >> 1;
			for (complex *p=a;p!=a+n;p+=l) 
				for (int k = 0; k < m; k++) {
					complex t = w[n / l * k] * p[k + m];
					p[k + m] = p[k] - t;
					p[k] = p[k] + t;
				}
		}
	}

	void dft(complex *a, int f) {
		if (f == 1) fft(a, o); else {
			fft(a, oi);
			for (int i = 0; i < n; i++) a[i].r /= n;
		}
	}

	void mul(complex *a, complex *b, int m) {
		init(m);
		dft(a, 1); dft(b, 1);
		for (int i = 0; i < n; i++) a[i] = a[i] * b[i];
		dft(a, -1);
	}
};
fff f;

int main() {
	int n1, n2, m, i, j;
	scanf("%d%d", &n1, &n2);
	for (i = 0; i < n1; i++) scanf("%lf", &a[i].r);
	for (i = 0; i < n2; i++) scanf("%lf", &b[i].r);
	m = n1 + n2 - 1;
	f.mul(a,b,m);
	for (i = 0; i < m; i++) ans[i] = floor(a[i].r + 0.5);
	for (i = m - 1; i >= 0; i--) printf("%d ", ans[i]);
	
	return 0;
}
