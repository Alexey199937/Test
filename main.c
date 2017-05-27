#include <stdio.h>
#include <string.h>


int main(int argc, char *argv[]) {
	FILE *f1;
    FILE *f2;
	float a[100];
	int i, j;
	do {
    argv = (char*) malloc (255 * sizeof(char));
    printf("Enter file name.\n");
    scanf("%s", argv);
	f1 = fopen(argv, "r");
	if (f1 == NULL) printf("Cannot open file.\n");  }
	while (f1 == NULL);

	do {
    argv = (char*) malloc (255 * sizeof(char));
    printf("Enter file name.\n");
    scanf("%s", argv);
	f2 = fopen(argv, "r+");
	if (f2 == NULL) printf("Cannot open file.\n");  }
	while (f2 == NULL);
    fread(a, sizeof(float), 10, f1);
    for (i = 0; i<5; i++)
printf("%f", a[i]);

}
