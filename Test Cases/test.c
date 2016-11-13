#include <stdlib.h>
#include <stdio.h>
#define ROUND 100
#define MAXN 30000000

int main (int argc, char* argv[]) {
    int i, j;
    for (i = 1; i <= ROUND; i++) {
	for (j = 1; j <= MAXN; j++) {}
	printf("%s-%d\n", argv[1], i);
    }
    return 0;
}
