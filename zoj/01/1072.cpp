#include <cstdio>
#include <memory>
#include <cstdlib>
#include <cstring>
using namespace std;

#define debug 1
const int MaxL = 260;
const int len[9] = {3, 3, 1, 1, 1, 1, 3, 3, 1};
char mem[MaxL];
char add[3];
char A;
char B;
int p;

inline int to_int(char c)
{
	if (c <= '9' && c >= '0') return c - '0';
	return c - 'A' + 10;
}

inline char to_char(int c)
{
	if (c >= 0 && c <= 9) return c + '0';
	return c - 10 + 'A';
}

inline int to_dec()
{
	return to_int(add[0]) * 16 + to_int(add[1]);
}

inline void gao0()
{
	add[0] = mem[p+1];
	add[1] = mem[p+2];
	A = mem[to_dec()];
	p += len[0];
}

inline void gao1()
{
	add[0] = mem[p+1];
	add[1] = mem[p+2];
	mem[to_dec()] = A;
	p += len[1];
}

inline void gao2()
{
	A ^= B ^= A ^= B;
	p += len[2];
}

inline void gao3()
{
	int sum(to_int(A) + to_int(B));
	A = to_char(sum % 16);
	B = to_char(sum / 16);
	p += len[3];
}

inline void gao4()
{
	int n(to_int(A));
	n = (n + 1) % 16;
	A = to_char(n);
	p += len[4];
}

inline void gao5()
{
	int n(to_int(A));
	n = (n + 15) % 16;
	A = to_char(n);
	p += len[5];
}

inline void gao6()
{
	if (A == '0')
	{
		add[0] = mem[p+1];
		add[1] = mem[p+2];
		p = to_dec();
		return;
	}
	p += len[6];
}

inline void gao7()
{
	add[0] = mem[p+1];
	add[1] = mem[p+2];
	p = to_dec();
}

inline void gao()
{
	int i;
	int j;
	A = '0';
	B = '0';
	p = 0;
	while (mem[p] != '8')
	{
		switch (mem[p])
		{
			case '0': gao0(); break;
			case '1': gao1(); break;
			case '2': gao2(); break;
			case '3': gao3(); break;
			case '4': gao4(); break;
			case '5': gao5(); break;
			case '6': gao6(); break;
			case '7': gao7(); break;
			default : throw "gao() error!"; break;
		}
	}
	puts(mem);
}

int main()
{	
#if debug
	freopen("f:\\in.txt", "r", stdin);
#endif
	scanf("%s", mem);
	while (mem[0] != '8')
	{
		gao();		
		scanf("%s", mem);
	}
	
	return 0;
}