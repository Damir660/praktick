#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <iostream>
#include <locale.h>
#include <windows.h>
#include <cstring>
#include <fstream>

using namespace std;

#define INF 9999999


FILE* file = fopen("text.txt", "a");


void Alg_Prima(int n, int** matr, int* selected)
{

	int no_edge;
	// Изначально установим  false 

	for (int i = 0; i < n; i++)
	{
		selected[i] = false;
	}

	no_edge = 0;

	// число ребер в минимальном остовном дереве будет 
	// всегда меньше (V -1), где V-число вершин в
	//графе


	selected[0] = true;

	int x;            //  номер строки
	int y;            //  номер столбца
	int sum = 0;


	printf("Ребро  :  Вес\n");

	while (no_edge < n - 1)
	{

		int min = INF;
		x = 0;
		y = 0;


		for (int i = 0; i < n; i++)
		{
			if (selected[i]) // если отмечена
			{
				for (int j = 0; j < n; j++)
				{
					if (!selected[j] && matr[i][j]) // не отмечена и есть ребро между
					{
						if (min > matr[i][j])
						{
							min = matr[i][j];
							x = i;
							y = j;

						}

					}

				}
			}
		}

		sum = sum + matr[x][y];

		printf("%d ", x);  printf(" - ");  printf("%d ", y);
		printf(" : ");  printf("%d\n", matr[x][y]);


		fprintf(file, "%d ", x); fprintf(file, " - "); fprintf(file, "%d ", y);
		fprintf(file, " : ");  fprintf(file, "%d\n", matr[x][y]);


		selected[y] = true;
		no_edge++;
	}

	printf("\nСтоимость минимального остовного дерева: %d", sum);
	fprintf(file, "\nСтоимость минимального остовного дерева: %d\n", sum);
	fprintf(file, "\n=========================================================================");
	printf("\n=========================================================================\n");

}

void Output(int** matr, int n) // вывод сгенерированной матрицы
{
	for (int i = 0; i < n; i++) // вывод сгенерированной матрицы
	{

		for (int j = 0; j < n; j++)
		{
			printf("%3d ", matr[i][j]);
		}
		printf("\n");
	}

	printf("\n   ");
}




int main()
{

	srand(time(0));
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int** matr; //указатель для массива указателей 
	int* selected; // Массив для отслеживания вершины
	int* stp;
	int n, d;


	printf(" Добро пожаловать! Выберите один из пунктов меню, что начать: \n\n");
	printf(" 1. Автоматическая генерация матрицы. (нажмите 1) \n");
	printf(" 2. Ручной ввод (нажмите 2) \n");
	printf(" 3. Завершить сеанс (нажмите 3)\n");
	printf("=========================================================================");

	d = _getch();

	if (d == '1')
	{
		printf("\n");
		printf("Введите размер матрицы: ");

		scanf("%d", &n);

		printf("=========================================================================");

		stp = (int*)malloc(n * sizeof(int));
		selected = (int*)malloc(n * sizeof(int)); //выделение памяти под массив отслеживания вершин

		matr = (int**)malloc(n * sizeof(int*)); //выделение памяти под массив указателей


		for (int i = 0; i < n; i++) //выделение памяти для массива значений
		{
			matr[i] = (int*)malloc(n * sizeof(int));
		}


		for (int i = 0; i < n; i++) // генерация массива случайных чисел
		{
			for (int j = 0; j < n; j++)
			{
				if (i == j)
				{
					matr[i][j] = 0;
				}

				if (i < j)
				{
					matr[i][j] = rand() % 80;
					matr[j][i] = matr[i][j];
				}

				if (matr[i][j] > 0)
				{
					stp[i]++;
				}
			}
		}

		printf("\nРезультат: \n");


		Output(matr, n); //вызов функции печати сгенерированного массива

		//printf("\nIzolir versh:\n");

		for (int i = 0; i < n; i++)
		{
			if (stp[i] == 0)
			{
				printf("Алгоритм не работает при наличии изолированных вершин");
				exit(0);
			}
		}

		Alg_Prima(n, matr, selected); //вызов функции реализации алгоритма Прима

	}


	if (d == '2')
	{
		printf("\n");
		printf(" Введите размер матрицы:");
		scanf("%d", &n);

		stp = (int*)malloc(n * sizeof(int));
		selected = (int*)malloc(n * sizeof(int)); //выделение памяти под массив отслеживания вершин

		matr = (int**)malloc(n * sizeof(int*)); //выделение памяти под массив указателей


		for (int i = 0; i < n; i++) //выделение памяти для массива значений
		{
			matr[i] = (int*)malloc(n * sizeof(int));
		}

		for (int i = 0; i < n; i++) // генерация массива чисел
		{
			for (int j = 0; j < n; j++)
			{
				printf("Введите элемент матрицы:\n");

				if (i == j)
				{
					matr[i][j] = 0;
					printf("%d\n", matr[i][j]);
				}

				if (i < j)
				{

					scanf("%d", &matr[i][j]);
					matr[j][i] = matr[i][j];
				}

				if (matr[i][j] > 0)
				{
					stp[i]++;
				}
			}
		}

		printf("Результат: \n");


		Output(matr, n); // вызов функции вывода результата генерации


		for (int i = 0; i < n; i++)
		{
			if (stp[i] == 0)
			{
				printf("Алгоритм не работает при наличии изолированных вершин");
				exit(0);
			}
		}

		Alg_Prima(n, matr, selected); // алгоритм прима

	}

	if (d == '3')
	{

		exit(0);

	}


	return 0;
}
