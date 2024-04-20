#include <iostream>
#include <fstream>//для открытия и работы с файлами
#include <string>
#include <cstdlib> // для получения рандомных чисел
#include <chrono> // для получения времени и замера времени работы куска программы

#include "function.h"

//функция для записи в файл
void write_arr(const std::string& filename, const int* arr, const int n);

//функция для чтения из файла
void read_arr(const std::string& filename, int*& arr, int& n);

int main()
{
	std::string filename = "array_data.txt";
		
	const int size = 10;
	int* rand_arr = new int[size];

	// используем текущее время, чтобы сгенерировать рандомные значения
	srand(time(nullptr));
	int lef_border = 1;
	// правая граница = range_len + left_border
	int range_len = 10;

	for (int i = 0; i < size; ++i)
	{
		// генерируем число в указанном диапазоне и записываем в массив
		rand_arr[i] = lef_border + rand() % range_len;
	}

	// записываем массив в файл
	write_arr(filename, rand_arr, size); 	

	int* array_from_file = nullptr;
	int n = 0;
	// читаем массив из файла
	read_arr(filename, array_from_file, n);

	for (int i = 0; i < size; i++)
	{
		std::cout << rand_arr[i] << " ";
	}

	// сохраняем время начала работы алгоритма
	auto start = std::chrono::high_resolution_clock::now();
	// запускаем сортировку
	
	//bubbleSort(array_from_file, size);
	
	mergeSort(array_from_file, 0, size - 1);

	// сохраняем время конца работы алгоритма
	auto finish = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double> elapsed = start - finish;
	// вычисляем продолжительность работы в сек. и выводим на экран
	std::cout << "Elapsed time: " << elapsed.count() << " sec" << std::endl;

	for (int i = 0; i < size; i++)
	{
		std::cout << array_from_file[i] << " ";
	}

	delete[] rand_arr;
	delete[] array_from_file;

	return 0;
}

void write_arr(const std::string& filename, const int* arr, const int n)
{
	std::fstream fs;
	//fstream::out — файл будет открыт на запись
	fs.open(filename, std::fstream::out);
	// проверяем, что файл успешно открыт
	if (fs.is_open())
	{
		std::cout << "out file!!" << std::endl;
		// записываем размер массива
		fs << n << '\n';
		for (int i = 0; i < n; ++i)
		{
			// записываем значения через пробел
			fs << arr[i] << ' ';
		}

		fs << '\n';

		// закрываем файл
		fs.close();
	}
}

void read_arr(const std::string& filename, int*& arr, int& n)
{
	std::fstream fs;
	//fstream::in — только на чтение.
	fs.open(filename, std::fstream::in);
	// проверяем, что файл успешно открыт
	if (fs.is_open())
	{
		std::cout << "in file!!2" << std::endl;
		// читаем размер массива
		fs >> n;
		arr = new int[n];
		for (int i = 0; i < n; ++i)
		{
			// читаем из файла разделительные символы - пробел и перенос строки
			fs >> arr[i];
		}
		// закрываем файл
		fs.close();
	}
}
