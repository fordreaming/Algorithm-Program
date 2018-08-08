#include <iostream>
using namespace std;

//交换两个数字的顺序
void Swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

//遍历输出数组的元素
void Traverse(int *a, int n)
{
	int i = 0;
	for (i; i < n; i++)
	{
		cout << "***" << a[i] ;
	}
	cout << endl;
}


//冒泡排序初级版（严格意义不叫冒泡排序,冒泡排序：两两比较相邻元素)
//最最简单交换排序
void BubbleSortInit(int *A, int n)
{
	int i = 0;
	for(i = 0; i < n-1; i++)
	{
		cout << "遍历前顺序" << endl;
		Traverse(A, n);
		int j;
		for (j = i+1; j < n; j++ )
		{
			//上浮——较小值
			if (A[i] > A[j])
			{
				Swap(&A[i], &A[j]);
			}
		}
		cout << "遍历前顺序" << endl;
		Traverse(A, n);
	}
}

//冒泡排序 上升
void BubbleSort_Up(int A[], int n)
{
	int i = 0;
	for (i; i < n-1; i++)
	{
		cout << "遍历前顺序" << endl;
		Traverse(A, n);
		int j;
		for (j = n -1; j >= i; j--)
		{
			//较小值上浮
			if (A[j-1] > A[j])
			{
				Swap(&A[j-1], &A[j]);
			}
		}
		cout << "遍历前顺序" << endl;
		Traverse(A, n);
	}
}

//冒泡排序
//n:数组的长度 下沉式
void BubbleSortDown(int A[], int n)
{
	for(int i = 0; i < n-1; i++)
	{
		cout << "遍历前顺序" << endl;
		Traverse(A, n);
		for(int j = 0; j < n-i-1; j++)
		{
			//较大的下沉
			if (A[j] > A[j+1])
			{
				Swap(&A[j], &A[j+1]);
			}
		}
		cout << "遍历后顺序" << endl;
		Traverse(A, n);
	}
}


//冒泡排序改进版__鸡尾酒排序(定向冒泡排序)
void CocktailSort(int A[], int n)
{
	int left = 0;
	int right = n -1;
	while (left < right)
	{
		cout << "从左向右遍历前顺序" << endl;
		Traverse(A, n);
		//从左向右进行冒泡排序
		for (int i = left; i < right; i++)
		{
			//较大值沉底
			if (A[i] > A[i+1])
			{
				Swap(&A[i], &A[i+1]);
			}
		}
		right--;
		cout << "从左向右遍历后顺序" << endl;
		Traverse(A, n);


		cout << "从右向左遍历前顺序" << endl;
		Traverse(A, n);
		//从右向左进行冒泡排序
		
		int j;
		for(j = right; j > left; j-- )
		{
			//较小值上升
			if (A[j-1] > A[j])
			{
				Swap(&A[j-1], &A[j]);
			}
		}
		cout << "从右向左遍历后顺序" << endl;
		Traverse(A, n);
		left++;
	}
}


//冒泡排序改进版_添加旗标
void BubbleSort_flag(int A[], int n)
{
	bool flag = true;
	for(int i = 0; i < n-1 && flag; i++)
	{
		cout << "遍历前顺序" << endl;
		Traverse(A, n);
		int j;
		for(j = n-1; j> i; j--)
		{
			flag = false;
			//上浮式
			//
			if (A[j-1] > A[j])
			{
				Swap(&A[j-1], &A[j]);
				flag = true;
			}
		}
		cout << "遍历后顺序" << endl;
		Traverse(A, n);
	}

}

//插入排序
void InsertSort(int A[], int n)
{
	int i = 1;//抓牌
	for(i; i < n; i++)
	{
		cout << "遍历前顺序" << endl;
		Traverse(A, n);
		int get = A[i];
		int j = i -1;
		while (j >= 0 && A[j] > get)
		{
			A[j+1] = A[j];
			j--;
		}
		A[j + 1] = get;
		cout << "遍历后顺序" << endl;
		Traverse(A, n);
	}
}

//插入排序改进
void InsertSortDichotomy(int A[], int n)
{
	int i = 1;
	for (i ; i < n; i++)
	{
		cout << "遍历前顺序" << endl;
		Traverse(A, n);
		int get = A[i];
		int left = 0;
		int right = i-1;
		//二分法定位新牌的位置
		while (left <= right)
		{
			int mid = (left+right)/2;
			if (A[mid] > get)
			{
				right = mid -1;
			}
			else
			{
				left = mid+1;
			}
		}
		
		//已经定位新牌的位置，将欲插入新牌位置的右边整体右移
		for(int j = i-1; j >= left; j--)
		{
			A[j+1] = A[j];
		}
		A[left] = get;	
		cout << "遍历后顺序" << endl;
		Traverse(A, n);
	}
}


//　希尔排序，也叫递减增量排序
//插入排序的高效改进
void ShellSort(int A[], int n)
{
	int h = 0;
	while(h <= n)
	{
		h = 3*h + 1;
	}
	while(h > 0)
	{
		//***********************************************************
		//类似于插入排序
		for (int i = h; i < n; i++)
		{
			cout << "遍历前顺序" << endl;
			Traverse(A, n);
			int get = A[i];
			int j = i- h;
			while (j >= 0 && A[j] > get)
			{
				A[j + h] = A[j];
				j = j-h;
			}
			A[j+h] = get;
			cout << "遍历后顺序" << endl;
			Traverse(A, n);
		}
		//***********************************************************
		h = (h - 1)/3;
	}
	
}

//归并排序:1、递归实现的归并排序； 2、非递归实现的归并排序

//合并两个已排序好的数组
void Mergy(int A[], int left, int mid, int right)
{

}

int main()
{
	int A[] = {3,2,4,1,5,7};
	//数组长度
	int length = sizeof(A)/sizeof(A[0]);
	//冒泡排序
	/*BubbleSortInit(A, length);*/
	/*BubbleSort_Up(A, length);*/
	//BubbleSort(A, length);
	//CocktailSort(A, length);
	/*BubbleSort_flag(A, length);*/
	//InsertSort(A, length);
	/*ShellSort(A, length);*/
	return 0;
}