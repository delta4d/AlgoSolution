#include <stdio.h>
#include <string.h>

char d[1 << 12], r[1 << 12];
int N;

int L() {
	int I, J, K;
	for (I = N - 1; I >= N / 2; I--) {
		if (d[I] == '0') {
			d[I] = '9';
		} else {
			d[I]--;
			break;
		}
	}
	if (I * 2 < N) return 0;
	for (I = J = 0; I * 2 < N; I++) {
		K = (r[I] - '0') + (d[I] - '0') + J;
		J = K / 10;
		r[I] = K % 10 + '0';
	}
	while (J) {
		K = (r[I] - '0') + J;
		J = K / 10;
		r[I] = K % 10 + '0';
		I++;
	}
	return 1;
}

void O() {
	int I, J, K;
	for (I = (1<<12)-1; I; I--) if (r[I] != '0') break;
	I = I < 0 ? 0 : I;
	while (I >= 0) {
		printf("%c", r[I]);
		I--;
	}
	printf("%c", '\n');
}

int main() {
	int I, J, K;
	while (fgets(d, 1 << 12, stdin)) {
		N = strlen(d);
		d[--N] = 0;
		if (N > 1 << 12 - 2) {
			printf("0\n");
			continue;
		}
		if (N - (N >> 1) - (N >> 1)) {
			d[N++] = '0';
			d[N] = 0;
		}
		memset(r, '0', sizeof(r));
		while (L());
		O();
	}
}