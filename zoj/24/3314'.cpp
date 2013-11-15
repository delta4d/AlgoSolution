#include <cstdio>
using namespace std;

char f[20][20];

int main() {
	FILE *in = fopen("c:\\gao\\in.txt", "r");
	FILE *out = fopen("c:\\gao\\out.txt", "w");	
	int i, j, k;
	
	for (k=0; k<26; ++k) {
		for (i=0; i<7; ++i) fscanf(in, "%s", f[i]);
		// 1
		fprintf(out, "\n");
		//fprintf(out, "{");
		for (i=0; i<7; ++i) {
			fprintf(out, "\"");
			fprintf(out, "%s", f[i]);
			fprintf(out, "\"%s", i==6?",\n":",\n");
		}
		fprintf(out, "\n");
		// 2
		//fprintf(out, "{");
		for (i=0; i<7; ++i) {
			fprintf(out, "\"");
			for (j=15; j>=0; --j) {
				fprintf(out, "%c", f[i][j]);
			}
			fprintf(out, "\"%s", i==6?",\n":",\n");
		}
		// 3
		fprintf(out, "\n");
		//fprintf(out, "{");
		for (i=6; i>=0; --i) {
			fprintf(out, "\"");
			for (j=15; j>=0; --j) {
				fprintf(out, "%c", f[i][j]);
			}
			fprintf(out, "\"%s", i==0?",\n":",\n");
		}
		// 4
		fprintf(out, "\n");
		//fprintf(out, "{");
		for (i=6; i>=0; --i) {
			fprintf(out, "\"");
			for (j=0; j<16; ++j) {
				fprintf(out, "%c", f[i][j]);
			}
			fprintf(out, "\"%s", i==0?",\n":",\n");
		}
	}

	fclose(in);
	fclose(out);
	return 0;
}