// Sort_Sort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int main()
{
	int array [14] = {3 ,5 ,6 ,4 ,8 ,9, 7, 5, 2, 1,0, 2, 46, 4 };
	double arrayd [ 5 ] = { 6.004,5,4,3,2 };
	show(array, 14);
	show(arrayd, 5);
//	selectSort(array, 14);
//	selectSort(arrayd, 5);
//	insertSort(array, 14);
//	insertSort(arrayd, 5);
//	bubbleSort(array, 14);
//	bubbleSort(arrayd, 5);
	mergeSort(array, 0, 13, 0);
	mergeSort(arrayd, 0, 4, 0);

	show(array, 14);
	show(arrayd, 5);
	system("pause");
    return 0;
}

