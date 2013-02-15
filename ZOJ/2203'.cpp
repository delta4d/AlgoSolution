#include <iostream>
#include <math.h>
using namespace std;

#define SIZE	1000
#define PRIMESIZE  (SIZE*(SIZE+1))/2

bool bprimes[PRIMESIZE+1];
bool used[SIZE+1];

long bcount, maxbcount, maxn;

void calcPrimes()
{
	for(int i=2; i<PRIMESIZE; i+=2) {
		bprimes[i] = false;
		bprimes[i+1] = true;
	}
	if (PRIMESIZE == 1)
		bprimes[SIZE-1] = false;

	int i=3;
	while (true) {
		while (i<=PRIMESIZE && !bprimes[i])
			i+=2;
		if (i>PRIMESIZE/2)
			break;
		for(int j=2*i; j<PRIMESIZE; j+=i)
			bprimes[j] = false;
		i+=2;
	}
}

bool sort(long a[], int index, int n, int m, int d)
{
	bcount++;
	if (index == m-n+1)
		return true;
	else {
		for(long val=n; val <= m; val++) {
			if (used[val])
				continue;
			bool ok = true;
			int sum = val;
			for(int j=1; j<d; j++) {
				if (index-j < 0)
					break;
				sum += a[index-j];
				if (bprimes[sum]) {
					ok = false;
					break;
				}
			}
			if (ok) {
				used[val] = true;
				a[index] = val;
				if (sort(a, index+1, n, m, d))
					return true;
				used[val] = false;
			}
		}
		return false;
	}
}

int main()
{
	long n, m, d;

	calcPrimes();
	cin >> n >> m >> d;
	while (n != 0) {
		long *a = new long[m-n+1];
		for(long i=n; i<=m; i++)
			used[i] = false;
		bool found = false;
		bcount=0;
		for(int i=n; i<=m; i++) {
			used[i] = true;
			a[0] = i;
			if (sort(a, 1, n, m, d)) {
				found = true;
				cout << a[0];
				for(long i=n+1; i<=m; i++)
					cout << ',' << a[i-n];
				cout << endl;
				break;
			}
			used[i] = false;
		}
		if (!found)
			cout << "No anti-prime sequence exists." << endl;
		if (bcount > maxbcount) {
			maxbcount = bcount;
			maxn = n;
		}
		delete [] a;
		cin >> n >> m >> d;
	}
	return 0;
}
