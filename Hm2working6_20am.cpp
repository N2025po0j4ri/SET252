#include <stdio.h>
#include <iostream>
using namespace std;
#define MAX 10

int i_array[MAX] = { 0,1,2,3,4,5,6,7,8,9 };

int* i_ptr, count;

int main(void)
{
	int length = 0;
	do
	{
		printf("Enter a size (1-100):");
		scanf_s("%d", &length);
	} while (length < 1 || length>100);
	printf("Size user entered : %d\n", length);

	long* palngValues = new long[length];

	for (int intIndex = 0; intIndex < length; intIndex += 1) {
		long val;
		//printf("%d\n", intIndex);
		printf("Enter value");
		scanf_s("%lu", &val);
		*(palngValues + intIndex) = val; //Assign content
		//palngValues += 1; //Move pointer to next address
	}
	for (int intIndex = 0; intIndex < length; intIndex++) {
		cout << "val at ";
		cout << intIndex;
		cout << " ";
		cout << *(palngValues + intIndex);
		cout << endl;
	}
	/*
	i_ptr = i_array;

	for (int count = 0; count < MAX; count++) {
		printf("%d\n", *i_ptr++);
	} */
	return 0;
}