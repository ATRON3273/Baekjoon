#define _CRT_SECURE_NO_WARNINGS
#define MAX 8

#include <stdio.h>

int a[MAX];
int visited[MAX];
int stack[MAX];

// 소트
void swap(int* a, int* b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
void sequential_sort(int a[], int n)
{
	int i, j;

	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
			{
				swap(&a[i], &a[j]);
			}
		}
	}
}

// 조합
void print_c()
{
	int i;
	for (i = 0; i < MAX; i++)
	{
		if (visited[i] == 1)
		{
			printf("%d ", a[i]);
		}
	}
	printf("\n");
}
void combination(int start, int count, int num, int range)
{
	int i;

	if (count == num)
	{
		print_c();
		return;
	}

	for (i = start; i < range; i++)
	{
		if (visited[i] == 0)
		{
			visited[i] = 1;
			combination(i, count + 1, num, range);
			visited[i] = 0;
		}
		else
		{
			continue;
		}
	}
}

// 순열
void print_p(int num)
{
	int i;
	for (i = 0; i < num; i++)
	{
		printf("%d ", stack[i]);
	}
	printf("\n");
}
void permutation(int count, int num, int range)
{
	int i;

	if (count == num)
	{
		print_p(num);
		return;
	}

	for (i = 0; i < range; i++)
	{
		if (visited[i] == 0)
		{
			visited[i] = 1;
			stack[count] = a[i];
			permutation(count + 1, num, range);
			visited[i] = 0;
		}
		else
		{
			continue;
		}
	}
}

int main()
{
	int N, M, i;
	// N : 출력할 숫자
	// M : 한 줄에 출력하는 숫자 수
	scanf("%d %d", &N, &M);

	for (i = 0; i < N; i++)
	{
		scanf("%d", &a[i]);
	}
	sequential_sort(a, N);

	combination(0, 0, M, N);
	// permutation(0, M, N);

	return 0;
}