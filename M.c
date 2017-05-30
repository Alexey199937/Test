#include <stdio.h>

struct package {
	int x;
	char c[255];
	float y;
};
int main(int argc, char *argv[]) {
	FILE *f;

	int i=0, size = 0;
	struct package p;
	do {
    argv = (char*) malloc (255 * sizeof(char));
    printf("Enter file name.\n");
    scanf("%s", argv);
	f = fopen(argv, "rb");
	if (f == NULL) printf("Cannot open file.\n");  }
	while (f == NULL);

	printf("Open file:\n");
	while (fread(&p, sizeof(struct package),1, f)) {
		printf("%d | %s | %f \n", p.x, p.c, p.y);
		i++;
	}
	fclose(f);
	free (argv);
	size = i * sizeof(struct package);
	printf("File size: %d bytes.\n", size);
	return(0);
}

