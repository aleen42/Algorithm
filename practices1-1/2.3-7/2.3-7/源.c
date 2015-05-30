#include <stdio.h>
#define MAXSIZE 1000
#define INFINITY 99999999

int data[] = { 6, 20, 4, 6, 12, 7, 2, 1, 4, 7 };


//int sizeofarray(int a[])
//{
//	int* p = a;
//	int num = 0;
//	while (*p++ != 0)
//		num++;
//	return num;
//}

void printf_array(int a[]);
void Merge(int A[], int p, int m, int q);
void MergeSort(int A[], int p, int q);
int Binary_Search(int A[], int p, int q, int key);
int CheckSum(int A[], int array_size, int sum);


int main()
{
	//printf("%d\n", data[11]);			
	//printf("%d\n", sizeof(data) / sizeof(int));
	
	printf_array(data);
	//printf("%d\n", Binary_Search(data, 0, sizeof(data) / sizeof(int) - 1, 4));
	
	switch (CheckSum(data, sizeof(data) / sizeof(int), 1))
	{
	case 0:
		printf("false\n");
		break;
	case 1:
		printf("true\n");
		break;
	default:
		break;
	}

	//printf("%d\n", data[1]);
	system("pause");
	return 0;
}


void printf_array(int a[])
{
	int* p = a;
	while (*p++ == 0)
		printf("%-3d", *(p - 1));
	p--;
	while (*p++ != 0)
		printf("%-3d", *(p - 1));
	printf("\n");
}

void Merge(int A[], int p, int m, int q)
{
	int n1 = m - p + 1;
	int n2 = q - (m + 1) + 1;
	int L[MAXSIZE], R[MAXSIZE];				//分别放进两个队列
	for (int i = 1; i <= n1; i++)
	{
		L[i] = A[p + i - 1];
	}
	for (int j = 1; j <= n2; j++)
	{
		R[j] = A[m + j];
	}
	L[n1 + 1] = INFINITY;
	R[n2 + 1] = INFINITY;
	int i = 1;
	int j = 1;
	for (int k = p; k <= q; k++)				//两对头比较，较小的放入
	{
		if (L[i] <= R[j])
		{
			A[k] = L[i];
			i++;
		}
		else
		{
			A[k] = R[j];
			j++;
		}
	}
}

int Binary_Search(int A[], int p, int q, int key)
{
	int index = -1;
	if (A[p] == key) 
		return index = p;
	if (A[q] == key)
		return index = q;
	if (p < q)
	{
		if (A[(p + q) / 2] == key)
			return index = (p + q) / 2;
		else if (A[(p + q) / 2] < key)
			return index = Binary_Search(A, (p + q) / 2 + 1, q - 1, key);
		else
			return index = Binary_Search(A, p + 1, (p + q) / 2 - 1, key);
	}
	else	
		return index;
}

void MergeSort(int A[], int p, int q)
{
	if (p < q)
	{
		int m = (p + q) / 2;
		MergeSort(A, p, m);
		MergeSort(A, m + 1, q);
		Merge(A, p, m, q);
	}
}

int CheckSum(int A[], int array_size, int sum)
{
	
	MergeSort(A, 0, array_size - 1);
	for (int i = 0; i < array_size; i++)
	{
		if (A[i] >= 0 && Binary_Search(A, 1, array_size - 1, sum - A[i]) != -1)
		{
			return 1;
		}
	}
	return 0;
}
