#include <cmath>
#include <cstdio>
#include <cstring>
#include <complex>
#include <algorithm>
using namespace std;

const double PI = acos(-1.0);
const int MAXN = 160000;

complex <double> x[MAXN], y[MAXN];
int out[MAXN];
char buf[MAXN];

void FFT(complex<double> *a,int len,int inv){//eps=1e-12 
    for (int i=0, n1=0, n2=0; i < len; ++i, n2 ^= (len/(i&-i)>>1), n1^=(i&-i))
		if (n1 > n2)
			swap(a[n1], a[n2]); 
    for(int m = 1; m <= len >> 1; m <<= 1){ 
        complex<double> w0(cos(PI / m), sin(PI / (inv * m))), w = 1, t; 
        for(int k = 0; k < len; k += (m << 1), w = 1) 
            for(int j = 0; j < m; ++j, w *= w0){ 
                t=w*a[k+j+m];a[k+j+m]=a[k+j]-t;a[k+j]+=t; 
            } 
    } 
    if(inv == -1) 
		for(int i = 0; i < len; ++i) 
			a[i] /= len; 
}

int main() {
	int i, j, k;
	int lx, ly;
	int len, ll;

	while (1 == scanf("%s", buf)) {
		for (lx=strlen(buf),i=0; i<lx; ++i) x[lx-i-1] = complex<double>::complex(buf[i]-'0', 0);
		scanf("%s", buf);
		for (ly=strlen(buf),i=0; i<ly; ++i) y[ly-i-1] = complex<double>::complex(buf[i]-'0', 0);
		for (len=1; len<lx*2||len<ly*2; len<<=1);
		for (i=lx; i<len; ++i) x[i] = complex<double>::complex(0, 0);
		for (i=ly; i<len; ++i) y[i] = complex<double>::complex(0, 0);
		FFT(x, len, 1);
		FFT(y, len, 1);
		for (i=0; i<len; ++i) x[i] *= y[i];
		FFT(x, len, -1);
		for (i=0; i<len; ++i) out[i] = x[i].real() + 0.5;
		for (i=0; i<len; ++i) out[i+1] += out[i] / 10, out[i] %= 10;
		ll = lx + ly;
		while (out[ll] <= 0 && ll > 0) --ll;
		for (i=ll; i>=0; --i) printf("%d", out[i]);
		puts("");
	}
	return 0;
}