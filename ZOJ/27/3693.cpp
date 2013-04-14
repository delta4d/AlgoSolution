#include <cstdio>
using namespace std;

int main() {
	int n, k;
	double w;

	while (3 == scanf("%d%lf%d", &n, &w, &k)) {
		++n, ++n, w *= 50;
		n -= n / k;
		w *= n;
		printf("%.2lf\n", w/100+5e-5);
	}

	return 0;
}
