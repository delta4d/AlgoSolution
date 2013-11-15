#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 1000010;
const int ten[7] = {1, 10, 100, 1000, 10000, 100000, 1000000};
bool visit[MAXN];
bool gaoding;
char res[7][MAXN];

struct node {
	int x;
	int d;
	node(int x=-1, int d=-1):x(x), d(d) {}
};

struct STACK {
	node s[1<<20];
	int rear;
	
	bool empty() {
		return rear == 0;
	}
	node top() {
		return s[rear-1];
	}
	void pop() {
		--rear;
	}
	void push(node a) {
		s[rear] = a;
		++rear;
	}
	void clear() {
		rear = 0;
	}
} stack;

void dfs(int n) {
	int i, j, k;
	int x, y, d, s(-1);
	node tt;
	
	memset(visit, false, sizeof(visit));
	visit[0] = true;
	stack.clear();
	stack.push(node(0, n));
	
	while (!stack.empty()) {
		tt = stack.top();
		x = tt.x, d = tt.d;
		if (d == ten[n] + n - 1) return;
		y = x / ten[n-1];
		y = x - y * ten[n-1];
		for (i=s+1; i<10; ++i) {
			k = y * 10 + i;
			if (!visit[k]) {
				visit[k] = true;
				res[n][d] = i + '0';
				stack.push(node(k, d+1));
				s = -1;
				break;
			}
		}
		if (i == 10) {
			visit[x] = false;
			s = x % 10;
			stack.pop();
		}
	}
}

void gen() {
	int i, j, k;
	for (i=1; i<=6; ++i) {
		for (j=0; j<i; ++j) res[i][j] = '0';
		dfs(i);
	}
}

int main() {
	int i, j, k;
	int n;
	//freopen("f:\\in.txt", "r", stdin);
	gen();
	scanf("%d", &n);
	while (n != 0) {
		puts(res[n]);
		scanf("%d", &n);
	}
	return 0;
}