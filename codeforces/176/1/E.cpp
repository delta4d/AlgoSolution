#include <cmath>
#include <cstdio>
#include <cstring>
#include <complex>
#include <iostream>
#include <algorithm>
using namespace std;

namespace DFT {
	typedef complex <double> CD;

	const int MAXN = 1 << 21;
	const double PI = acos(-1.0);
	
	CD b[MAXN], t[MAXN];

	void FFT(CD a[], const int N, const bool inv) {
		const double sgn = inv ? 1 : -1;
		for (int n=N>>1,t=1; n>0; n>>=1,t<<=1) {
			CD w0(cos(PI/t), sgn*sin(PI/t)), w(1.0, 0.0);
			for (int j=0; j<t; ++j) {
				for (int i=0; i<n; ++i) {
					b[i+n*j] = a[i+2*n*j] + w * a[i+n+2*n*j];	
					b[i+n*(j+t)] = a[i+2*n*j] - w * a[i+n+2*n*j];
				}
				w *= w0;
			}	
			for (int i=0; i<N; ++i) a[i] = b[i];
		}
		if (inv) for (int i=0; i<N; ++i) a[i] /= N;
	}

	void sqr(CD a[], const int N) {
		FFT(a, N, false);	
		for (int i=0; i<N; ++i) a[i] *= a[i];
		FFT(a, N, true);
	}
}

const int MAXN = DFT::MAXN;
const double eps = 1e-5;

DFT::CD a[MAXN];
bool has[MAXN];
int out[MAXN], sz;

inline bool is_0(const double x) { return fabs(x) < eps; }

int main() {
	int n, m;

	scanf("%d%d", &n, &m);
	for (int i=0,k; i<n; ++i) {
		scanf("%d", &k);
		a[k] = 1, has[k] = true;
	}
	a[0] = 1;
	DFT::sqr(a, MAXN);
	for (int i=1; i<=m; ++i) if (!is_0(a[i].real()) && !has[i]) { puts("NO"); return 0; }
	for (int i=1; i<=m; ++i) if (is_0(a[i].real()-2)) out[sz++] = i;
	puts("YES");
	printf("%d\n", sz);
	for (int i=0; i<sz; ++i) printf("%d%s", out[i], i==sz-1?"\n":" ");

	return 0;
}

// 3410236	 Mar 27, 2013 8:21:42 AM	delta_4d	 286E - Ladies' Shop	 GNU C++	Accepted	3625 ms	108800 KB
