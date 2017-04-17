// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <stdlib.h>
#include <iostream>


// TODO:  �ڴ˴����ó�����Ҫ������ͷ�ļ�

//	�鿴����
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

//	�����㷨ģ�廯ʵ��
//	ѡ������	O(n^2)	O(1)
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

//	��������	O(n^2)	O(1)
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

//	ð������	O(n^2) O(1)
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
