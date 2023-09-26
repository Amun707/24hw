#include <iostream>
#include <cstdlib>
#include <ctime>

//Задача 1.
template <typename T>
void show_arr(T arr[], int size) {
	std::cout << "{";
	for (int i = 0; i < size; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b}\n";
}

void fill_arr(int arr[], int size, int min, int max) {
	srand(time(NULL));
	for (int i = 0; i < size; i++)
		arr[i] = rand() % (max - min) + min;
}

//Задача 2.

template <typename T>
void resize_arr(T arr1[], const int length) {
	std::cout << "{ ";
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b }" << std::endl;
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

	//Задача 2.
	std::cout << "Задача 2.\nВведите текущую длину массива -> ";
	std::cin >> n;
	int* K = new int[n];
	fill_arr(K, n, 27, 48);
	show_arr(K, n);

	std::cout << "Введите новую длину массива -> ";
	std::cin >> m;
	int* N = new int[m];
	fill_arr(N, m, 44, 77);
	show_arr(N, m);

	const int size1 = 5;
	int arr[size1];
	const int size = m;
	int arr1[size1];

	std::cout << "Итоговый массив:\n";
	std::swap(*arr1, *arr);
	resize_arr(arr1, size1);







	return 0;
