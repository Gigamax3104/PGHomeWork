#include	<stdio.h>
#include	<stdlib.h>
#include	<time.h>
#define MAX 10

void FisherYates(int list[]);

int main() {
	int list[MAX] = { 1,2,3,4,5,6,7,8,9,10 };

	FisherYates(list);

	for (int i = 0; i < MAX; i++) {
		printf("%d\n", list[i]);
	}
}

void FisherYates(int list[]) {
	srand((unsigned int)time(NULL));

	int random = 0;

	for (int i = MAX - 1; i > 1; i--) {
		random = rand() % MAX;

		int save = list[i];
		list[i] = list[random];
		list[random] = save;
	}
}