#include <conio.h>
#include <iostream>
#include <locale.h>
#include <windows.h>
#include <cstring>
#include <fstream>

using namespace std;

#define INF 9999999


FILE* file = fopen("text.txt", "a");


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
		return 0;
	}

	if (choice == '1') {
		printf("Введите размер матрицы: ");
		scanf("%d", &n);
		// выделение памяти и генерация случайной матрицы
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i < j) matr[i][j] = rand() % 80;
			}
		}
	}
	if (choice == '2') {
		printf("Введите размер матрицы: ");
		scanf("%d", &n);
		// ввод элементов матрицы вручную
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i < j) scanf("%d", &matr[i][j]);
			}
		}
	}