#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <malloc.h>
#include <locale.h>
#include <queue>

using namespace std;

#pragma warning (disable:4996)

void BFSD(int* VIS, int** M, int n, queue <int> q, int v)
{
	VIS[v] = 0;
	q.push(v);
	while (!q.empty())
	{
		v = q.front();
		q.pop();
		for (int i = 0; i < n; i++)
		{
			if (M[v][i] == 1 && VIS[i] == -1)
			{
				q.push(i);
				VIS[i] = VIS[v] + 1;
			}
		}
	}
}

int main()
{
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));

	int n, V = 0;
	int v;
	int** M, * VIS;
	printf("Размер: ");
	scanf("%d", &n);
	printf("\n");
	queue <int> q;
	VIS = (int*)malloc(n * sizeof(int));
	M = (int**)malloc(n * sizeof(int*));

	for (int i = 0; i < n; i++)
	{
		M[i] = (int*)malloc(n * sizeof(int));
	}

	for (int i = 0; i < n; i++)
	{

		for (int j = 0; j < n; j++)
		{
			M[i][j] = rand() % 2;
			M[j][i] = M[i][j];
			if (i == j)
			{
				M[i][j] = 0;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		VIS[i] = -1;
		for (int j = 0; j < n; j++)
		{
			printf("%d ", M[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("Введите вершину графа: ");
	scanf("%d", &v);
	printf("Обход графа: \n");
	BFSD(VIS, M, n, q, v - 1);
	for (int i = 0; i < n; i++)
	{
		printf("%d - %d\n", i + 1, VIS[i]);
	}
	getch();
	return 0;
}

