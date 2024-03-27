#include <stdio.h>
#include <iostream>
using namespace std;
#define MAX 10

int i_array[MAX] = { 0,1,2,3,4,5,6,7,8,9 };

int* i_ptr, count;



long* MakeArray(long palngValues[], int& length) {
	int temp = 0;
	do
	{
		printf("Enter a size (1-100):");
		scanf_s("%d", &temp);
	} while (temp < 1 || temp>100);
	length = temp;
	printf("Size user entered : %d\n", length);

	palngValues = new long[length];

	for (int intIndex = 0; intIndex < length; intIndex += 1) {
		long val;
		//printf("%d\n", intIndex);
		printf("Enter value");
		scanf_s("%lu", &val);
		*(palngValues + intIndex) = val; //Assign content
		//palngValues += 1; //Move pointer to next address
	}
	return palngValues;
}

int main(void)
{
	long* palngValues = 0;
	int length = 0;
	palngValues = MakeArray(palngValues, length);
	cout << "length is ";
	cout << length;
	cout << endl;
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