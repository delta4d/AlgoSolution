#include <iostream>
using namespace std;

typedef unsigned long long ULL;

inline bool bit(const ULL x, const ULL p) { return x & (1llu << p);	}

int main() {
	ULL L, R, p;

	cin >> L >> R;
	for (p=63; p<=63&&bit(L, p)==bit(R, p); --p);
	cout << (1llu << (p + 1)) - 1 << endl;

	return 0;
}

// 3299220	 Mar 13, 2013 7:09:59 PM	delta_4d	 276D - Little Girl and Maximum XOR	 GNU C++	Accepted	15 ms	0 KB
