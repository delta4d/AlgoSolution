#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

//const double eps = 1e-5;

int main() {
	int H, U, D, F;
	double cur_height, offset, step_size, next_height;
	int i, j, k;
	int day;
	//freopen("f:\\in.txt", "r", stdin);
	while (scanf("%d %d %d %d", &H, &U, &D, &F), H) {
		cur_height = 0, offset = F * U / 100.0, step_size = U;
		for (day=1; ; ++day) {
			//printf("height: %.2lf\n", cur_height);
			next_height = cur_height + step_size;
			if (next_height > H) {
				printf("success on day %d\n", day);
				break;
			}
			if (next_height < D) {
				printf("failure on day %d\n", day);
				break;
			}
			cur_height = next_height - D;
			step_size = max(0.0, step_size-offset);
		}
	}
	return 0;
}