#include <bits/stdc++.h>
using namespace std;
int a[10000];
int main() {
	int k, n1, n2, n3, t1, t2, t3;
	cin>>k>>n1>>n2>>n3>>t1>>t2>>t3;
	auto f=[&](int n, int t) {for (int i=0; i+n<k; ++i) a[i+n]=max(a[i]+t,a[i+n]);};
	f(n1, t1), f(n2, t2), f(n3, t3);
	cout<<a[k-1]+t1+t2+t3<<endl;
	return 0;
}

// 7275602	2014-07-28 12:20:19	delta_4d	D - Washer, Dryer, Folder	GNU C++0x	Accepted	15 ms	0 KB
