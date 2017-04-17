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
	int i, j,selIndx;
	T temp;
	if(arrayLen > 1)
	for (i = 0;i < arrayLen;++i)
	{
		temp = array [ i ];
		selIndx = i;
		for (j = i + 1; j < arrayLen;++j)
		{
			if (!mode ? array [ selIndx ] > array [ j] : array [ selIndx ] < array [ j])
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
				array [ j ] = array [ j - 1];
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
