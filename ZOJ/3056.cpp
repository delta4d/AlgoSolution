#include <map>
#include <cstdio>
#include <string>
#include <ctype.h>
#include <cstring>
#include <algorithm>
using namespace std;

map<string, string> dict;
map<string, string>::iterator it;
char buff[128], word[32];

int main() {
	int i, j, k;
	//freopen("f:\\in.txt", "r", stdin);
	while (scanf("%s", word), word[0]!='D') {
		strcpy(buff, word);
		if ((k = strlen(buff)) > 2) sort(buff+1, buff+k-1);
		dict.insert(make_pair(string(buff), string(word)));
	}
	gets(buff);
	while (gets(buff)) {
		buff[strlen(buff)+1] = '$';
		for (i=k=0; !i||buff[i-1]; ++i) {
			if (islower(buff[i])) {
				word[k++] = buff[i];
			} else {
				if  (k > 0) {
					word[k] = '\0';
					sort(word+1, word+k-1);
					it = dict.find(string(word));
					if (it != dict.end()) printf("%s", (it->second).c_str());
				}
				printf("%c", buff[i]);
				k = 0;
			}
		}
		puts("");
	}
	return 0;
}