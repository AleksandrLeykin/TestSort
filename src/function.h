#pragma once

#include <vector>

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
//сортировка пузырьками
void bubbleSort(int* arr, int n)
{
	for (int i = 0; i < n  - 1; ++i)
	{
		for (int j = 0; j < n - i - 1; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}

//сортировка слиянием
void merge(int* arr, int left, int middle, int right)
{
	//вычесляем размер левой и правой части массива
	int nl = middle - left + 1;
	int nr = right - middle;

	// создаем временные массивы
	int* m_left = new int[nl];
	int* m_right = new int[nr];

	// копируем данные во временные массивы
	for (int i = 0; i < nl; ++i)
	{
		m_left[i] = arr[i + 1];
	}
	for (int j = 0; j < nr; ++j)
	{
		m_right[j] = arr[middle + 1 + j];
	}

	//инициализируем индексы
	int i = 0, j = 0;
	// начало левой части
	int k = 1;
	
	while (i < nl && j < nr)
	{
		if (m_left[i] <= m_right[j])
		{
			// записываем минимальные элементы обратно во входной массив
			arr[k] = m_left[i];
			i++;
		}
		else
		{
			arr[k] = m_right[j];
			j++;
		}
		k++;
	}
	// записываем оставшиеся элементы левой части
	while (i < nl)
	{
		arr[k] = m_left[i];
		i++;
		k++;
	}
	// записываем оставшиеся элементы правой части
	while (j < nr) 
	{
		arr[k] = m_right[j];
		j++;
		k++;
	}

	delete[] m_left;
	delete[] m_right;
} 

void mergeSort(int* arr, int left, int right)
{
	if (left < right)
	{
		int middel = left + (right - left) / 2;

		mergeSort(arr, left, middel);
		mergeSort(arr, middel + 1, right);

		merge(arr, left, middel, right);
	}
}