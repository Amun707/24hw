#include <iostream>
#include <cstdlib>
#include <ctime>


template <typename T>
void show_arr(T arr[], int size) {
	std::cout << "{";
	for (int i = 0; i < size; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b}\n";
}
template <typename T>
void fill_arr(T arr[], int size, int min, int max) {
	srand(time(NULL));
	for (int i = 0; i < size; i++)
		arr[i] = rand() % (max - min) + min;
}


//Задача 2.
template <typename T>
void resize_arr(T*& arr, const int length, int newlen) {
	if (length == newlen) // завершение функции, если длина не должна измениться
		return;

	if (newlen <= 0) { // создание нейтрального указателя и завершение функции, если длина <= 0
		delete[] arr;
		arr = nullptr;
		return; 
	}

	// Шаг 1. Выделение памяти под новый временный массив нужной длины
	T* tmp = new T[newlen]{}; // массив нулей

	// Шаг 2. Копирование элементов старого массива в новый
	int minlen = length < newlen ? length : newlen;
	for (int i = 0; i < minlen; i++)
		tmp[i] = arr[i];

	// Шаг 3. Удаление элементов старого массива
	delete[] arr;

	// Шаг 4. Перенаправление указателя на новый массив
	arr = tmp;
}


int main() {
	system("chcp 1251>nul");

	int n, m, r;
	//Задача 1.
	std::cout << "Задача 1.\nВведите длины массивов: ";
	std::cin >> n >> m;
	int* A = new int[n];
	int* B = new int[m];
	fill_arr(A, n, 10, 31);
	fill_arr(B, m, 50, 71);

	std::cout << "Массив A:\n";
	show_arr(A, n);
	std::cout << "Массив B:\n";
	show_arr(B, m);

	int* C = new int[n + m];
	for (int i = 0; i < n; i++)
		C[i] = A[i];
	for (int i = n; i < n + m; i++)
		C[i] = B[i - n];
	std::cout << "Массив С:\n";
	show_arr(C, n + m);
	delete[] A;
	delete[] B;
	std::cout << std::endl;


	//Задача 2.
	std::cout << "Задача 2.\nВведите текущую длину массива -> ";
	std::cin >> n;
	int* K = new int[n];
	std::cout << "Изначальный массив:\n";
	fill_arr(K, n, 27, 48);
	show_arr(K, n);

	std::cout << "Введите новую длину массива -> ";
	int newn;
	std::cin >> newn;

	resize_arr(K, n, newn);

	std::cout << "Итоговый массив:\n";
	show_arr(K, newn);


	return 0;
}