#include <stdio.h>

void printArray(int arr[], int len);
void ascendingOrder(int arr[], int len);
int halfCell(int x);
bool notInArrayYet(int arr[], int len, int element);
void problemH(int result[], int &len, int m, int n);

int main()
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
	return 0;
}

void printArray(int arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
}

void ascendingOrder(int arr[], int len)
{
	for (int i = 0; i < len - 1; i++)
		for (int j = i + 1; j < len; j++)
		{
			if (arr[i] > arr[j])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
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

bool notInArrayYet(int arr[], int len, int element)
{
	for (int i = 0; i < len; i++)
	{
		if (arr[i] == element)
			return false;
	}
	return true;
}

void problemH(int result[], int &len, int m, int n)
{

	for (int i = halfCell(m); i < m; i++)
	{
		if (notInArrayYet(result, len, (i*n)))
		{
			result[len] = (i*n);
			len++;
		}
	}		

	for (int i = halfCell(n); i < n; i++)
	{
		if (notInArrayYet(result, len, (i*m)))
		{
			result[len] = (i*m);
			len++;
		}
	}
	ascendingOrder(result, len);
}
