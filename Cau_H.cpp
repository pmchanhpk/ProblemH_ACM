#include <stdio.h>
#include<conio.h>

void getArray(int arr[], int length)
{
	for (int i = 0; i < length; i++)
	{
		scanf("%d", &arr[i]);
	}
}

void printArray(int arr[], int length)
{
	for (int i = 0; i < length; i++)
	{
		printf("%d ", arr[i]);
	}
}

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void ascendingOrder(int arr[], int length)
{
	for (int i = 0; i < length - 1; i++)
	{
		for (int j = i+1; j <length; j++)
		{
			if (arr[i] > arr[j])
				swap(arr[i], arr[j]);
		}
	}
}

int halfCell(int x)
{
	if (x % 2 == 0)
		return (x / 2);
	else
		return (x / 2 + 1);
}

bool notInArrayYet(int arr[], int length, int element)
{
	for (int i = 0; i < length; i++)
	{
		if (arr[i] == element)
			return false;
	}
	return true;
}

void problemH(int result[], int &length, int m, int n)
{

	for (int i = halfCell(m); i < m; i++)
	{
		if (notInArrayYet(result, length, (i*n)))
		{
			result[length] = (i*n);
			length++;
		}
	}		

	for (int i = halfCell(n); i < n; i++)
	{
		if (notInArrayYet(result, length, (i*m)))
		{
			result[length] = (i*m);
			length++;
		}
	}
	ascendingOrder(result, length);
}

void main()
{
	int m[100], n[100], numberOfTestCases;
		scanf("%d", &numberOfTestCases);

	for (int i = 0; i < numberOfTestCases; i++)
	{
		scanf("%d", &m[i]);
		scanf("%d", &n[i]);
	}

	for (int i = 0; i < numberOfTestCases; i++)
	{
		int arrResult[200], arrLength = 0;
		problemH(arrResult, arrLength, m[i], n[i]);
		printArray(arrResult, arrLength);
		printf("\n");
	}	
	_getch();
}