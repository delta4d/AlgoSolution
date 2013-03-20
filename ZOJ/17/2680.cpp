#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

struct Times {
	int h;
	int m;
	double angle;
}f[5];

int cmp(const void *a, const void *b) {
	struct Times *c = (struct Times *)a;
	struct Times *d = (struct Times *)b;
	
	if(c -> angle - d -> angle < 0) {
		return -1;
	} else if (c -> angle - d -> angle > 0) {
		return 1;
	} else {
		if (c -> h != d -> h) {
			return c -> h - d -> h; 
		} else {
			return c -> m - d -> m;
		}
	}
}

int main(void) {
	int TestCase;
	int k;
	int i;
	double t;
	
	scanf("%d", &TestCase);
	
	for (k=0; k<TestCase; ++k) {
		for (i=0; i<5; ++i) {
			scanf("%d", &f[i].h);
			getchar();
			scanf("%d", &f[i].m);
			
			t = fabs(-30 * f[i].h + 5.5 * f[i].m);
			
			while (fabs(t) > 180) {
				t -= 360;
			}
			
			f[i].angle = fabs(t);
		}
		
		qsort(f, 5, sizeof(f[0]), cmp);
		
		if (f[2].h > 9) {
			printf("%d:", f[2].h);
		} else if (f[2].h > 0) {
			printf("0%d:", f[2].h);
		} else {
			printf("00:");
		}
		
		if (f[2].m > 9) {
			printf("%d\n", f[2].m);
		} else if (f[2].m > 0) {
			printf("0%d\n", f[2].m);
		} else {
			printf("00\n");
		}
	}
	
	return 0;
}
