#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 36;

char A[MAXN][3], B[MAXN][3], C[MAXN][3];

bool is_stable(char X[][3], const int n) {
	for (int k=1; k<=9; ++k) {
		int i=0, j=0;
		while (i < n && j < n) {
			for (; i<n&&A[i][1]!='0'+k; ++i);
			for (; j<n&&X[j][1]!='0'+k; ++j);
			if (i < n && j >= n || i >= n && j < n) return false;
			if (i < n && j < n && A[i][0] != X[j][0]) return false;
			++i, ++j;
		}
	}
	return true;
}

void BubbleSort(const int n) {
	for (int i=0; i<n; ++i) {
		for (int j=n-1; j>=i+1; --j) {
			if (B[j][1] < B[j-1][1]) {
				swap(B[j][0], B[j-1][0]);
				swap(B[j][1], B[j-1][1]);
			}
		}
	}		
	for (int i=0; i<n; ++i) printf("%s%s", B[i], i==n-1?"\n":" ");
	printf("%s\n", is_stable(B, n)?"Stable":"Not stable");
}

void SelectionSort(const int n) {
	for (int i=0; i<n; ++i) {
		int mn = i;
		for (int j=i; j<n; ++j) if (C[j][1] < C[mn][1]) mn = j;
		swap(C[i][0], C[mn][0]);	
		swap(C[i][1], C[mn][1]);	
	}	
	for (int i=0; i<n; ++i) printf("%s%s", C[i], i==n-1?"\n":" ");
	printf("%s\n", is_stable(C, n)?"Stable":"Not stable");
}

int main() {
	int i, j, k;
	int m, n;

	for (scanf("%d", &n), i=0; i<n; scanf("%s", A[i]), strcpy(B[i], A[i]), strcpy(C[i], A[i]), ++i);
	BubbleSort(n);
	SelectionSort(n);

	return 0;
}
