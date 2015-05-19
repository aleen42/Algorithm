#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int index_KMP(char *s, char *t, int pos);
void get_next(char *t, int *);

char s[10] = "abcacbcba";
char t[4] = "bca";
int next[4];
int pos = 0;

int main()
{
	int n;
	get_next(t, next);
	n = index_KMP(s, t, pos);
	printf("%d", n);
	system("pause");
	return 0;
}

int index_KMP(char *s, char *t, int pos)
{
	int i = pos, j = 1;
	while (i <= (int)strlen(s) && j <= (int)strlen(t))
	{
		if (j == 0 || s[i] == t[j - 1])
		{
			i++;
			j++;
		}
		else j = next[j];
	}
	if (j>(int)strlen(t))
		return i - strlen(t) + 1;
	else
		return 0;
}

void get_next(char *t, int *next)
{

	int i = 1, j = 0;
	next[0] = next[1] = 0;
	while (i<(int)strlen(t))
	{
		if (j == 0 || t[i] == t[j])
		{
			i++;
			j++;
			next[i] = j;
		}
		else j = next[j];
	}

}