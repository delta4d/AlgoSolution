#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 1000010;
const int ten[7] = {1, 10, 100, 1000, 10000, 100000, 1000000};
bool visit[MAXN];
bool gaoding;
char res1[11], res2[111], res3[1011], res4[10011], res5[100011], res6[1000011];

struct node {
	int x;
	int d;
	node(int x=-1, int d=-1):x(x), d(d) {}
};

struct STACK {
	node s[1<<19];
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

void dfs1(int n) {
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
				res1[d] = i + '0';
				stack.push(node(k, d+1));
				s = -1;
				break;
			}
		}
		if (i == 10) {
			visit[x] = false;
			s = x - (x / 10) * 10;
			stack.pop();
		}
	}
}

void dfs2(int n) {
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
				res2[d] = i + '0';
				stack.push(node(k, d+1));
				s = -1;
				break;
			}
		}
		if (i == 10) {
			visit[x] = false;
			s = x - (x / 10) * 10;
			stack.pop();
		}
	}
}

void dfs3(int n) {
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
				res3[d] = i + '0';
				stack.push(node(k, d+1));
				s = -1;
				break;
			}
		}
		if (i == 10) {
			visit[x] = false;
			s = x - (x / 10) * 10;
			stack.pop();
		}
	}
}

void dfs4(int n) {
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
				res4[d] = i + '0';
				stack.push(node(k, d+1));
				s = -1;
				break;
			}
		}
		if (i == 10) {
			visit[x] = false;
			s = x - (x / 10) * 10;
			stack.pop();
		}
	}
}

void dfs5(int n) {
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
				res5[d] = i + '0';
				stack.push(node(k, d+1));
				s = -1;
				break;
			}
		}
		if (i == 10) {
			visit[x] = false;
			s = x - (x / 10) * 10;
			stack.pop();
		}
	}
}

void dfs6(int n) {
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
				res6[d] = i + '0';
				stack.push(node(k, d+1));
				s = -1;
				break;
			}
		}
		if (i == 10) {
			visit[x] = false;
			s = x - (x / 10) * 10;
			stack.pop();
		}
	}
}

void gen() {
	for (int i=0; i<6; ++i) {
		res1[i] = res2[i] = res3[i] = res4[i] = res5[i] = res6[i] = '0';
	}
	dfs1(1);
	dfs2(2);
	dfs3(3);
	dfs4(4);
	dfs5(5);
	dfs6(6);
}

int main() {
	int i, j, k;
	int n;
	//freopen("f:\\in.txt", "r", stdin);
	gen();
	scanf("%d", &n);
	while (n != 0) {
		switch (n) {
			case 1: puts(res1); break;
			case 2: puts(res2); break;
			case 3: puts(res3); break;
			case 4: puts(res4); break;
			case 5: puts(res5); break;
			case 6: puts(res6); break;
			default: break;
		}
		scanf("%d", &n);
	}
	return 0;
}