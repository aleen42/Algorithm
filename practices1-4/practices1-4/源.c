#include <stdio.h>
#define MAXSIZE 1000
#define INFINITY 99999999

int data1[] = { 11, 11, 11, 11, 11, 11, INFINITY };						//m = 6
int data2[] = { 10, 10, 10, 10, 10, 10, INFINITY };						    //n = 3
int merge_array[MAXSIZE] = { 0 };
int array_size_data1 = sizeof(data1) / sizeof(int) - 1;
int array_size_data2 = sizeof(data2) / sizeof(int) - 1;

void printf_array(int A[], int array_size);
void Merge(int A[], int B[]);
int kth_Search(int A[], int B[], int A_array_size, int B_array_size, int k);		//k = 8

int main()
{
	Merge(data1, data2);
	printf_array(data1, array_size_data1);
	printf_array(data2, array_size_data2);
	//printf_array(merge_array, array_size_data1 + array_size_data2);
	for (int i = 1; i <= array_size_data1 + array_size_data2; i++)
		kthsmallest(data1, data2, array_size_data1, array_size_data2, i);
		//printf("%-4d", kthsmallest(data1, data2, array_size_data1, array_size_data2, i));
	printf("\n");
	//printf("%d\n", kth_Search(data1, data2, array_size_data1, array_size_data2, 5));
	system("pause");
	return 0;
}

//int kth_Search(int A[], int B[], int A_array_size, int B_array_size, int k)
//{
//	if (A_array_size + B_array_size < k || k <= 0)
//		return -1;
//	if (A_array_size == 0)
//		return B[k - 1];
//	if (B_array_size == 0)
//		return A[k - 1];
//	//if (k == 1)										
//	//	return A[0] > B[0] ? B[0] : A[0];
//	//if (k == 2)
//	//	return A[0] >= B[0] ? A[0] : B[0];			
//	int low_A = (k - 1) * A_array_size / (A_array_size + B_array_size);		//low_A = 4
//	//if (A[low_A - 1] == A[low_A]) 
//	//	low_A--;
//	int up_B = k - (low_A + 1) - 1;											//up_B
//
//	//printf("%d:    %-4d,%-4d\n", k, A[low_A], B[up_B]);
//	while (A[low_A] != INFINITY)
//	{
//		if (A[low_A] >= B[up_B] || up_B < 0)
//		{
//			if (A[low_A - 1] < B[up_B + 1])
//				return A[low_A] <= B[up_B + 1] ? A[low_A] : B[up_B + 1];
//			else
//				return A[low_A - 1];
//		}
//		else
//		{
//			low_A++;
//			up_B--;
//			//if (A[low_A+1] >= B[k - (low_A + 1) - 1])
//		}
//	}
//	return B[k - A_array_size - 1];
//}

void Merge(int A[], int B[])
{
	int i = 0;
	int j = 0;
	for (int k = 0; k <= array_size_data1 + array_size_data2 - 1; k++)
	{
		if (A[i] <= B[j])
		{
			merge_array[k] = A[i];
			i++;
		}
		else
		{
			merge_array[k] = B[j];
			j++;
		}
	}
}

void printf_array(int A[], int array_size)
{
	for (int i = 0; i <= array_size - 1; i++)
		printf("%-4d", A[i]);
	printf("\n");
}



int kthsmallest(int A[], int B[], int A_array_size, int B_array_size, int k)
{
	if (A_array_size == 0)
		return B[k - 1];
	if (B_array_size == 0)
		return A[k - 1];
	if (k == 1)										
		return A[0] > B[0] ? B[0] : A[0];
	if (k == A_array_size + B_array_size)
		return (A[A_array_size - 1] > B[B_array_size - 1]) ? A[A_array_size - 1] : B[B_array_size - 1];
	int low_A = (k - 1) * A_array_size / (A_array_size + B_array_size);		//low_A = 4
	int up_B = k - 1 - low_A;
	if (up_B >= B_array_size)
	{
		up_B = B_array_size - 1;
		low_A = k - B_array_size;
	}
	/*printf("%d:    %-4d,%-4d\n", k, low_A, up_B);*/

	if (((low_A == 0) || (A[low_A - 1] <= B[up_B])) && (B[up_B] <= A[low_A]))
		return B[up_B];
	if (((up_B == 0) || (B[up_B - 1] <= A[low_A])) && (A[low_A] <= B[up_B]))
		return A[low_A];
	if (A[low_A] <= B[up_B]) 
		return kthsmallest(A + low_A + 1, B, A_array_size - low_A - 1, up_B, k - low_A - 1);
	else 
		return kthsmallest(A, B + up_B + 1, low_A, B_array_size - up_B - 1, k - up_B - 1);
}