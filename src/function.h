#pragma once

#include <vector>

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
//���������� ����������
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

//���������� ��������
void merge(int* arr, int left, int middle, int right)
{
	//��������� ������ ����� � ������ ����� �������
	int nl = middle - left + 1;
	int nr = right - middle;

	// ������� ��������� �������
	int* m_left = new int[nl];
	int* m_right = new int[nr];

	// �������� ������ �� ��������� �������
	for (int i = 0; i < nl; ++i)
	{
		m_left[i] = arr[i + 1];
	}
	for (int j = 0; j < nr; ++j)
	{
		m_right[j] = arr[middle + 1 + j];
	}

	//�������������� �������
	int i = 0, j = 0;
	// ������ ����� �����
	int k = 1;
	
	while (i < nl && j < nr)
	{
		if (m_left[i] <= m_right[j])
		{
			// ���������� ����������� �������� ������� �� ������� ������
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
	// ���������� ���������� �������� ����� �����
	while (i < nl)
	{
		arr[k] = m_left[i];
		i++;
		k++;
	}
	// ���������� ���������� �������� ������ �����
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