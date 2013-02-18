#include <cstdio>
using namespace std;

int main() {
    int x;
    scanf("%d", &x);
    puts(!(x&1)&&x>=4?"YES":"NO");
    return 0;
}

//#	When	Who	Problem	Lang	Verdict	Time	Memory
//527996	 Jul 4, 2011 6:10:05 PM	delta_4d	 A - Watermelon	 GNU C++	Accepted	 30 ms	 1300 KB
