#include <stdio.h>
#include <math.h>

void requestInteger(char* tag, int* container) {
	printf("Masukkan nilai %s (bilangan bulat): ", tag);
	scanf("%d", container);
}

/* Menghitung jumlah unit satuan dalam input */
int countUnit(int input) {
	int count = 0;

	while (input > 0) {
		count++;
		input /= 10;
	}

	return count;
}

void printOutput(int input) {
	int unitCount = countUnit(input);

	for (int i = 1; i <= unitCount; i++) {
		// Ambil nilai unit ke-i dari kiri
		int temp = input / (int) pow(10, unitCount - i);
		temp %= 10;
		printf("%d", temp);

		// print '0' sesuai dengan satuannya
		for (int j = 0; j < unitCount - i; j++) {
			printf("0");
		}
		printf("\n");
	}
}

void main() {
	int input;
	requestInteger("input", &input);
	printOutput(input);
}