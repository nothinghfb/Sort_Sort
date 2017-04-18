// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <stdlib.h>
#include <iostream>


// TODO:  在此处引用程序需要的其他头文件

//	查看数组
template<typename T> void show(const T * const array, const int arrayLen);

template<typename T>
void show(const T * const array, const int arrayLen)
{
	using namespace std;
	for (int i = 0;i < arrayLen;++i)
	{
		cout << array [ i ] << " ";
	}
	cout << endl;
}




//	排序算法模板化实现
//	选择排序	O(n^2)	O(1)
template<typename T> void selectSort(T *array, const int arrayLen, const int mode = 0);

template<typename T>
void selectSort(T *array, const int arrayLen, const int mode /*= 0*/)
{
	int i, j, selIndx;
	T temp;
	if (arrayLen > 1)
		for (i = 0;i < arrayLen;++i)
		{
			temp = array [ i ];
			selIndx = i;
			for (j = i + 1; j < arrayLen;++j)
			{
				if (!mode ? array [ selIndx ] > array [ j ] : array [ selIndx ] < array [ j ])
				{
					temp = array [ j ];
					selIndx = j;
				}
			}
			array [ selIndx ] = array [ i ];
			array [ i ] = temp;
		}
}


//	插入排序	O(n^2)	O(1)
template<typename T> void insertSort(T *array, const int arrayLen, const int mode = 0);

template<typename T>
void insertSort(T *array, const int arrayLen, const int mode /*= 0*/)
{
	int i, j, insIndx;
	T temp;
	if (arrayLen > 1)
		for (i = 1;i < arrayLen;++i)
		{
			j = i;
			temp = array [ j ];
			if (!mode ? array [ j - 1 ] > temp : array [ j - 1 ] < temp)
			{
				temp = array [ j ];
				while (j >= 1 && ( !mode ? array [ j - 1 ] > temp : array [ j - 1 ] < temp ))
				{
					array [ j ] = array [ j - 1 ];
					--j;
				}
			}
			array [ j ] = temp;
		}
}



//	冒泡排序	O(n^2) O(1)
template<typename T> void bubbleSort(T *array, const int arrayLan, const int mode = 0);

template<typename T>
void bubbleSort(T *array, const int arrayLan, const int mode /*= 0*/)
{
	int i, j;
	T temp;
	if (arrayLan > 1)
		for (i = 0;i < arrayLan;++i)
		{
			for (j = 0;j < arrayLan - 1;++j)
			{
				if (!mode ? array [ j ] > array [ j + 1 ] : array [ j ] < array [ j + 1 ])
				{
					temp = array [ j ];
					array [ j ] = array [ j + 1 ];
					array [ j + 1 ] = temp;
				}
			}
		}
}



//	归并排序	O(nlogn)
//	合并子串函数
template<typename T> void mergeArray(T *array, const int leftInd, const int midInd, const int rightInd,const int mode = 0);

template<typename T>
void mergeArray(T *array, const int leftInd, const int midInd, const int rightInd, const int mode /*= 0*/)
{
	int i, j, k, n1, n2;
	n1 = midInd - leftInd + 1;
	n2 = rightInd - midInd;
	if (n1 <= 0 || n2 <= 0)
	{
		return;
	}

	T *leftArray = new T [ n1 ];
	T *rightArray = new T [ n2 ];

	for (i = 0, k = leftInd;i < n1;++i, ++k)
	{
		leftArray [ i ] = array [ k ];
	}
	for (i = 0, k = midInd + 1;i < n2;++i, ++k)/*********/
	{
		rightArray [ i ] = array [ k ];
	}
	for (k = leftInd, i = 0, j = 0;i < n1&&j < n2;++k)
	{
		if (!mode ? leftArray [ i ] < rightArray [ j ] :leftArray [ i ] > rightArray [ j ])
		{
			array [ k ] = leftArray [ i ];
			++i;
		}
		else
		{
			array [ k ] = rightArray [ j ];
			++j;
		}
	}
	if (i < n1)
	{
		for (j = i;j < n1;++j, ++k)
		{
			array [ k ] = leftArray [ j ];
		}
	}
	if (j < n2)
	{
		for (i = j;i < n2;++i, ++k)
		{
			array [ k ] = rightArray [ i ];
		}
	}

	delete []leftArray;
	delete []rightArray;
}



template<typename T> void mergeSort(T* array, const int beginInd, const int endInd,const int mode = 0);

template<typename T>
void mergeSort(T* array, const int beginInd, const int endInd, const int mode /*= 0*/)
{
	if (beginInd < endInd)
	{
		int midInd = ( beginInd + endInd ) / 2;
		mergeSort(array, beginInd, midInd, mode);
		mergeSort(array, midInd +1, endInd, mode);
		mergeArray(array, beginInd, midInd, endInd, mode);
	}
}

//	快速排序	O(nlogn)
template<typename T> void quickSortSubFun(T*array, const int low, const int high,const int mode = 0);

template<typename T>
void quickSortSubFun(T*array, const int low, const int high,const int mode /*= 0*/)
{
	int i, j;
	T temp;
	if (low >= high)return;
	i = low;
	j = high;
	temp = array [ i ];
	while (i < j)
	{
		while (i < j &&(!mode? array [ j ] >= temp : array[j] < temp))
		{
			--j;
		}
		if (i < j)
		{
			array [ i++ ] = array [ j ];
		}
		while (i < j && (!mode ? array [ i ] < temp :array[ i ] >= temp))
		{
			++i;
		}
		if (i < j)
		{
			array [ j-- ] = array [ i ];
		}
	}
	array [ i ] = temp;
	quickSortSubFun(array, low, i - 1, mode);
	quickSortSubFun(array, i + 1, high, mode);
}

template<typename T> void quickSort(T *array, const int len, const int mode = 0);

template<typename T>
void quickSort(T *array, const int len, const int mode /*= 0*/)
{
	quickSortSubFun(array, 0, len - 1, mode);
}
