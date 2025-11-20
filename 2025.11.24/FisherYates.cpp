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

	int idx = 0;
	int random = 0;
	int memory[MAX - 1];

	for (int i = MAX - 1; i > 1; i--) {
		random = rand() % (i - 1);

		if (idx > 0) {
			for (int i = 0; i < idx;) {

				if (list[random] != memory[i]) {
					i++;
				}
				else {
					random = rand() % (i - 1);
					i = 0;
				}
			}
		}

		memory[idx] = list[random];
		int save = list[i];
		list[i] = list[random];
		list[random] = save;
		idx++;
	}
}