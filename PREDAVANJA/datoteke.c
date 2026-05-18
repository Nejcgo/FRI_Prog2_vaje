#include <stdlib.h>
#include <stdio.h>

FILE* file;

int main() {
	// ODPREMO DATOTEKO
	file = fopen("file.txt", "r");

	if (file == NULL) {
		printf("Upsi :I\n");
		exit(1);
	}

	// NEK NAŠ BULLŠIT
	void* jože = &jože;

	char a[6], b[6];

	int arr1[10];
	int* arr2 = (int*) calloc(10, sizeof(int));

	printf("1: %d\n2: %d\n", (int) sizeof(arr1), (int) sizeof(arr2));

	//fprintf(stdout, "Dober dan, svet!\n");

	fscanf(file, "%s %s", a, b);

	printf("%s %s\n", a,b);

	/*for (int i = 0; i < 100; i++)
	{
		fprintf(file, "%d\n", i);
	}*/
	

	//POČISTIMO SA SABO
	fclose(file);
}