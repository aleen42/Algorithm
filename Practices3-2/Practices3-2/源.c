#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int run_time;
	int completion_time;
}job;

int main()
{
	// 3 + 11 + 21 + 36
	// We found that choose the min running time each time will be the best
	job times[4];
	times[0].run_time = 3;
	times[1].run_time = 8;
	times[2].run_time = 10;
	times[3].run_time = 15;
	
	//the last one whose completion time should be the sum
	//the last second one whose completion time will have the least one when the last one job has the max running time
	int time = 0;
	int sum = 0;
	for (int i = 0; i < 4; i++)
	{
		time += times[i].run_time;
		times[i].completion_time = time;
	}

	for (int i = 0; i < 4; i++)
	{
		sum += times[i].completion_time;
	}
	printf("average time: %lf\n", (double)sum / 4);

	system("pause");
	return 0;
}