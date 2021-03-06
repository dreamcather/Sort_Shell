// ShellSort_v1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <ctime>
int arr[9] = { 1,4,10,23,57,132,301,701,1750 };
void Show(int* mas, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%i \n", mas[i]);
	}
}
void Dive(int* mas,int shift,int k,int step)
{
	if (step > 0)
	{
		if (mas[k*(step - 1) + shift] < mas[k*step+shift])
		{
			return;
		}
		else
		{
			int tmp = mas[k*step + shift];
			mas[k*step + shift] = mas[k*(step - 1) + shift];
			mas[k*(step - 1) + shift] = tmp;
			Dive(mas, shift, k,step - 1);
		}
	}
}
void Flood(int* mas, int shift, int k, int n)
{
	int step = (int)((n - shift-1) / k) + 1;
	for (int i = 0; i < step; i++)
	{
		Dive(mas, shift, k, i);
	}
}
void Deluge(int*mas, int k, int n)
{
	for (int i = 0; i < k; i++)
	{
		Flood(mas, i, k, n);
	}
}
void ShellSort(int *mas, int n)
{
	for (int i = 9; i >= 0; i--)
	{
		Deluge(mas, arr[i], n);
	}
}
int Search(int* mas, int n, int tmp)
{
	int mid;
	int left = 0;
	int right = n - 1;
	while (right - left > 1)
	{
		mid = (right + left) / 2;
		if (mas[mid] == tmp)
		{
			break;
		}
		if (mas[mid] < tmp)
		{
			left = mid;
		}
		else
		{
			right = mid;
		}
	}
	if ((mid != n - 1) && (mas[mid + 1] < tmp))
	{
		mid++;
	}
	else
	{
		if ((mid != 0) && (mas[mid] > tmp))
		{
			mid--;
		}
	}
	printf("Search %i \n", mas[mid]);
	return mid;
}
void Merge(int* f_mas, int* s_mas, int f_n, int s_n, int f_s, int s_s,int *res,int r_s)
{
	for (int i = 0; i < f_n + s_n; i++)
	{
		if (f_s == f_n)
		{
			res[r_s] = s_mas[s_s];
			s_s++;
			r_s++;
		}
		else
		{
			if (s_s == s_n)
			{
				res[r_s] = s_mas[f_s];
				f_s++;
				r_s++;
			}
			else
			{
				if (f_mas[f_s] < s_mas[s_s])
				{
					res[r_s] = f_mas[f_s];
					f_s++;
					r_s++;
				}
				else
				{
					res[r_s] = s_mas[s_s];
					s_s++;
					r_s++;
				}
			}
		}
	}
}
int main()
{
	srand(time(0));
	int* mas = new int[100];
	for (int i = 0; i < 100; i++)
	{
		mas[i] = rand() % 200;
	}
	ShellSort(mas, 50);
	int* mas_s = mas + 50;
	ShellSort(mas_s, 50);
	int* mas_t = new int[100];
	Merge(mas, mas_s, 50, 50, 0, 0, mas_t, 0);
	Show(mas_t, 100);
    return 0;
}

