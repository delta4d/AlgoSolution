#include <cstdio>
#include <cstring>
using namespace std;


const int two[30] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 
                   8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576,
				   2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728};
char buff[10];

inline int tran() {
	int x((buff[0]-'0')*10+buff[1]-'0');
	int i;
	for (i=0; i<buff[3]-'0'; ++i) x *= 10;
	return x;
}

inline int gao(const int n) {
	int i;
	for (i=0; n>=two[i]; ++i);
	return ((n - two[i-1]) << 1) + 1;
}

int main() {
	int n;
	int i, j, k;
	//freopen("f:\\in.txt", "r", stdin);
	//freopen("f:\\out.txt", "w", stdout);
	scanf("%s", buff);
	while (strcmp(buff, "00e0") != 0) {
		n = tran();
		printf("%d\n", gao(n));
		scanf("%s", buff);
	}
	return 0;
}