#include<stdio.h>
#include<math.h>

const int two[32] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 
8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 
8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824};

struct Cash {
	long C[5];
	long visit;
}f[10001];

int main(void) {
	long n;
	long u;
	long k;
	long i;
	long j;
	long t;
	long add;
	long temp;
	long price;
	long num[5];
	long len[5];
	long bi[100];
	long pr[5] = {0, 1, 5, 10 ,25};
	/*freopen("f:\\in.txt", "r", stdin);*/
	scanf("%ld %ld %ld %ld %ld", &price, num+1, num+2, num+3, num+4);
	while (price != 0 || num[1] != 0 || num[2] != 0 || num[3] != 0 || num[4] != 0) {
			
		if(num[0] == 0 && price % 5 != 0) {
         	printf("Charlie cannot buy coffee.\n");	
       	 	goto done;
        }
		t = 1;
		for (i=1; i<5; ++i) {
			temp = num[i];
			k = 0;
			while (temp != 0) {
				bi[t] = pr[i] << k;
				++t;
				temp >>= 1;
				++k;
			}
			len[i] = t-1;
		}
		
		for (i=0; i<=price; ++i) {
			f[i].visit = 0;
			
			for (k=1; k<5; ++k) {
				f[i].C[k] = 0;
			}
		}
		
		f[0].visit = 1;
		
		for (i=1; i<=len[4]; ++i) {
			if (i <= len[1]) {
				add = bi[i];
				k = 1;
			} else if (i <= len[2]) {
				add = bi[i] / pr[2];
				k = 2;
			} else if (i <= len[3]) {
				add = bi[i] / pr[3];
				k = 3;
			} else {
				add = bi[i] / pr[4];
				k = 4;
			}
			
			for (j=price; j>=0; --j) {
				if (f[j].visit == 1) {
					t = j + bi[i];
					
					if ((t <= price) && (f[j].C[k] + add <= num[k])) {			
						if (f[t].visit == 0) {
							f[t].visit = 1;
							
							for (u=1; u<5; ++u) {
								f[t].C[u] = f[j].C[u];
							}
								
							f[t].C[k] += add;
						} else {
							if (f[t].C[1] + f[t].C[2] + f[t].C[3] + f[t].C[4] < f[j].C[1] + f[j].C[2] + f[j].C[3] + f[j].C[4] + add) {
								for (u=1; u<5; ++u) {
									f[t].C[u] = f[j].C[u];
								}
								
								f[t].C[k] += add;
							}
						}
					}
				}
			}
		}
		
		if (f[price].visit == 0) {
			printf("Charlie cannot buy coffee.\n");
		} else {
			printf("Throw in %ld cents, %ld nickels, %ld dimes, and %ld quarters.\n", f[price].C[1], f[price].C[2], f[price].C[3], f[price].C[4]);
		}
	done:
		scanf("%ld %ld %ld %ld %ld", &price, num+1, num+2, num+3, num+4);
	}
	
	return 0;
}