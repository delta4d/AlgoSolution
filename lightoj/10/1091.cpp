#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

bool e[10][10], v[10][10];
int x[10];

void print_space(int n) {
	for (int i=0; i<n; ++i) printf("  ");
}

void print_print(int d, int n) {
	print_space(d);
	printf("print(");
	for (int i=0; i<n; ++i) printf("%c%s", x[i]+'a', i==n-1?");\n":", ");
}

void print_print_f(int n) {
	printf("void print(");
	for (int i=0; i<n; ++i) printf("int %c%s", i+'a', i==n-1?"){\n":", ");
	printf("  printf(\"");
	for (int i=0; i<n; ++i) printf("%%d%s", i==n-1?"\\n\", ":" ");
	for (int i=0; i<n; ++i) printf("%c%s", i+'a', i==n-1?");\n":", ");
	puts("}");
}


bool ok(int n) {
	for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) v[i][j] = e[i][j];
	for (int k=0; k<n; ++k) for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) {
		if (v[i][k] && v[k][j]) v[i][j] = true;
	}
	int tot = 0, m = n * (n - 1) >> 1, d[10] = {0};
	for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) if (v[i][j]) ++tot, ++d[i];
	if (tot < m) return false;
	pair <int, int> c[10];
	for (int i=0; i<n; ++i) c[i] = make_pair(d[i], i);
	sort(c, c+n);
	for (int i=n-1; i>=0; --i) x[n-1-i] = c[i].second;
	return true;
}

void print_sort(int d, int n) {
	if (ok(n)) {
		print_print(d, n);
	} else {
		for (int i=0; i<n; ++i) for (int j=i+1; j<n; ++j) if (!v[i][j] && !v[j][i]) {
			print_space(d);
			printf("if (%c < %c)\n", i+'a', j+'a');
			e[i][j] = true;
			print_sort(d+1, n);

			print_space(d);
			printf("else\n");
			e[i][j] = false, e[j][i] = true;
			print_sort(d+1, n);

			e[j][i] = false;
			return;
		}
	}
}

int main() {
	int tc, cn = 0, n;
	for (scanf("%d", &tc); tc--; ) {
		memset(e, false, sizeof(e));
		for (int i=0; i<10; ++i) x[i] = i;
		scanf("%d", &n);
		printf("Case %d:\n", ++cn);
		print_print_f(n);
		printf("void sort(");
		for (int i=0; i<n; ++i) printf("int %c%s", i+'a', i==n-1?") {\n":", ");
		print_sort(1, n);
		puts("}");
	}
	return 0;
}

// 302322	2013-12-21 23:59:53	 1091 - The Fastest Sorting Ever!	 C++	 0.052	 1092	Accepted
