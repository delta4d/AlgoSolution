#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <cstdlib>
using namespace std;

#define ACCEPTED 0
#define WRONG_ANSWER 1
#define PRESENTATION_ERROR 2

const char dl[] = "------------------------------------------------------";
const char AC[] = "Accpted";
const char WA[] = "Wrong Answer";
const char PE[] = "Presentation Error";
const int MaxL = 1024;
FILE *my = fopen("f:\\out.txt", "r");
FILE *sd = fopen("f:\\res.txt", "r");
FILE *er = fopen("f:\\error.txt", "w");
char my_ans[MaxL];
char sd_ans[MaxL];
int error;
struct er_msg {
	int rank;
	char sd[MaxL];
	char my[MaxL];
	void gao(char s[]) {
		int len(strlen(s));
		int i, j, k;
		for (i=len-1; i>=0; --i) {
			if (s[i] == '\n' || s[i] == '\0') continue;
			break;
		}
		s[i+1] = '\0';
	}
	er_msg(int _r, char _s[], char _m[]):rank(_r) {
		sd[0] = my[0] = '\0';
		gao(_s);
		gao(_m);
		strcpy(sd, _s);
		strcpy(my, _m);
	}
	void output() {
		printf("%-5d%-15s: %s\n", rank, "Correct Answer", sd);
		printf("     %-15s: %s\n", "Your Answer", my);
	}
};
vector<er_msg> ver_msg;

inline void is_pe(int &error, char my[], char sd[]) {
	int i, j, k;
	int pm(0), ps(0);
	char tmy[MaxL], tsd[MaxL];
	if (error == WRONG_ANSWER) return;
	for (i=0; my[i]; ++i) if (my[i] != ' ') tmy[pm++] = my[i];
	tmy[pm] = '\0';
	for (i=0; sd[i]; ++i) if (sd[i] != ' ') tsd[ps++] = sd[i];
	tsd[ps] = '\0';
	if (strcmp(tmy, tsd) == 0) error = PRESENTATION_ERROR;
}

int main() {
	ver_msg.clear();
	error = false;
	int n(0);
	int i, j, k;
	bool is_read;
    while (fgets(my_ans, MaxL, my) && fgets(sd_ans, MaxL, sd)) {
    	++n;
        if (strcmp(my_ans, sd_ans) != 0) {
        	is_pe(error, my_ans, sd_ans);
        	if (error == WRONG_ANSWER) ver_msg.push_back(er_msg(n, sd_ans, my_ans));
        }
    }
    fgets(sd_ans, MaxL, sd);
	is_read = false;
	while (error != WRONG_ANSWER && !feof(my)) {
		is_read = true;
		fgets(my_ans, MaxL, my);
		for (i=0; my_ans[i]!='\n'&&my_ans[i]; ++i) if (my_ans[i] != ' ') {
			error = WRONG_ANSWER;
			break;
		}
	}
	if (is_read && error == ACCEPTED) error = PRESENTATION_ERROR;
	is_read = false;
	while (error != WRONG_ANSWER && !feof(sd)) {
		is_read = true;
		fgets(sd_ans, MaxL, sd);
		for (i=0; sd_ans[i]!='\n'&&sd_ans[i]; ++i) if (sd_ans[i] != ' ') {
			error = WRONG_ANSWER;
			break;
		}
	}
	if (is_read && error == ACCEPTED) error = PRESENTATION_ERROR;
	if (error == WRONG_ANSWER) {
		for (i=0; i!=ver_msg.size(); ++i) {
			fprintf(er, "%-5d%-15s: %s\n", ver_msg[i].rank, "Correct Answer", ver_msg[i].sd);
			fprintf(er, "     %-15s: %s\n", "Your Answer", ver_msg[i].my);
			fprintf(er, "%s\n", dl);
		}
	} else if (error == PRESENTATION_ERROR) {
		fprintf(er, "%s\n", PE);
	} else {
		fprintf(er, "%s\n", AC);
	}
	
    return 0;
}
