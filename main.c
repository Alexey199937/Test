#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "sort.h"

int main(void) {
	float t;
	long int key;
	tree *root=NULL;
	size_t i, n, result,flag;
	FILE *fp;
	data *k;
	stat f;
	char name[255];

	printf("Enter size of array:\n");
	scanf("%d", &n);

	printf("Enter:\n1 for read from a file.\n2 for keyboard input.\n3 for random data.\n");
	scanf("%d", &flag);

	switch (flag) {
	case 1:
		printf("Please enter file name:\n");
		scanf("%s", &name);
		break;
	case 2:
		printf("Enter your data\n");
		read_in_file(n);
		strcpy(name, "Entering data.csv");
		break;
	case 3:
		frcreate(n);
		printf("I create random array.\n");
		strcpy(name, "Entering data.csv");
		break;
	default:
		printf("Eror.Wrong data\n");
		return(0);
		break;
	}


	fp = fopen(name, "r");
	while (fp == NULL) {
		printf("Eror.Can't open file. Try again.\n");
		scanf("%s", &name);
		fp = fopen(name, "r");
	}

	printf("Enter searching element:");
	scanf("%ld", &key);

	k = (data*)malloc(n * sizeof(data));
	for (i = 0; i < n; i++)
		if (fscan_struct(fp, &k[i]) == 0) {
			printf("Eror.End file\n");
			n = i;
			break;
		}

	//Unsorted data
	//Linear search
	t = clock();
	result=linear_search(k, n,key,&f);
	t = (clock() - t) / CLOCKS_PER_SEC;
	f.time = t;
	result_search(f,result);

	//Sort
	//Buble
	printf("Start buble sort.\n");
	t = clock();
	f=buble_sort(k, n);
	t = (clock() - t) / CLOCKS_PER_SEC;
	printf("End buble sort.\n-----\n");
	f.time = t;
	result_sort(k,n,f);
	free(k);


	//Insert sort
	k= (data*)malloc(n * sizeof(data));
	rewind(fp);
	for (i = 0; i < n; i++)
		if (fscan_struct(fp, &k[i]) == 0) {
			printf("Eror.End file\n");
			n = i;
			break;
		}
	printf("Start insert sort.\n");
	t = clock();
	f=insert_sort(k, n);
	t = (clock() - t) / CLOCKS_PER_SEC;
	printf("End insert sort.\n-----\n");
	f.time = t;
	result_sort(k, n,f);
	free(k);


	//qsort
	k = (data*)malloc(n * sizeof(data));
	rewind(fp);
	for (i = 0; i < n; i++)
		if (fscan_struct(fp, &k[i]) == 0) {
			printf("Eror.End file\n");
			n = i;
			break;
		}
	printf("Start qSort sort.\n");
	t = clock();
	f=qSort(k, 0, n-1);
	t = (clock() - t) / CLOCKS_PER_SEC;
	printf("End qsort sort.\n-----\n");
	f.time = t;
	result_sort(k,n,f);
	free(k);

	//tree_sort
	k = (data*)malloc(n * sizeof(data));
	rewind(fp);
	for (i = 0; i < n; i++)
		if (fscan_struct(fp, &k[i]) == 0) {
			printf("Eror.End file\n");
			n = i;
			break;
		}
	printf("Start tree sort sort.\n");
	t = clock();
	f=tree_sort(&root,k,n);
	t = (clock() - t) / CLOCKS_PER_SEC;
	printf("End tree sort.\n-----\n");
	f.time = t;
	result_sort(k, n, f);

	//Sorted data
	//Interpolating Search
	t = clock();
	result=interpolatingSearch(k, n, key,&f);
	t = (clock() - t) / CLOCKS_PER_SEC;
	f.time = t;
	result_search(f, result);

	//Tree search
	t = clock();
	result=search_tree(&root, key,&f);
	t = (clock() - t) / CLOCKS_PER_SEC;
	f.time = t;
	result_search(f, result);
	fclose(fp);
	return 0;
}
