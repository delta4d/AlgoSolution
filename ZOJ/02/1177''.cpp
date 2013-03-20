#include <cstdio>
#include <cstring>
using namespace std;

typedef struct Num {
	int num[200009];
 	int len;
} Num;
Num a, b;
bool used[10][10005];

int Cmp(Num &a, Num &b) {
	if (a.len > b.len) {
		return 1;
	} else if (a.len < b.len) {
		return -1;
	} else {
  		int i;
  		for (i=a.len-1; i>=0; --i) {
   			if (a.num[i] > b.num[i]) return 1;
   			else if (a.num[i] < b.num[i]) return -1;
  		}
 	}
 	return 0;
}

int main() {
	int n,k,i,j,tempi,temp=0;
	scanf("%d", &n);
	while(n--) {
	  	scanf("%d", &k);
	  	for(i=0; i<200009; ++i)
	   		b.num[i] = 9;
	  	b.len = 200009;
	  	for(i=1; i<=9; ++i) {
	   		j = 0;
	   		temp = 0;
	   		tempi = i;
	   		memset(used, 0, sizeof(used));
	   		for(int ii=0; ii<200009; ++ii)
	    	a.num[ii] = 0;
	   		while(used[tempi][temp] != 1) {
	   			//printf("(%d, %d)", tempi, temp);
			    used[tempi][temp] = 1;
			    a.num[j] = (k * tempi + temp) % 10;
			    temp = (k * tempi + temp) / 10;
			    tempi = a.num[j];
			    ++j;    
		   	}
		   	puts("");
	  		if(i == tempi && temp == 0) a.len = j;
	   		else continue;
	   		if(Cmp(a, b) < 0)
	    	b = a;
	  	}
	  	for(i=b.len-1; i>=0; --i)
	   		printf("%d", b.num[i]);
		printf("\n");
		printf("len: %d\n", b.len);
	  	if(n > 0)
	   		printf("\n");
 	}
 	return 0;
}