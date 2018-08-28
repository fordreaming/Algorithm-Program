//#参考文章：https://www.cnblogs.com/eniac12/p/5329396.html及大话数据结构
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
	//前置条件
	//
	cout << "mergy" <<endl;
	cout << "left:  " << left <<"  mid:  " << mid << "  right:  " << right << endl;
	int len = right - left + 1;
	int i = left;//数组1的初始位置
	int j = mid+1;//数组2的初始位置
	//辅助空间len
	int *temp = new int[len];
	int index = 0;
	//不变条件
	//i <= mid && mid <j <= right
	while (i <= mid && j <=right)
	{
		temp[index++] = A[i] < A[j]?A[i++]:A[j++];
	}
	while (i <= mid)
	{
		temp[index++] = A[i++];
	}
	while (j <= right)
	{
		temp[index++] = A[j++];
	}
	//数组复制到A中
	int k;
	for(k = 0; k < len; k++)
	{
		A[left++] = temp[k];
	}
}

//递归实现归并排序
//自顶向下
void MergeSortRecursion(int A[], int left, int right)
{
	cout << "recursion" << endl;
	cout << "left:  " << left << "  right  " << right << endl;
	//递归开始回溯
	if (left == right)
	{
		return;
	}
	//递归条件
	int mid = (left + right)/2;
	MergeSortRecursion(A, left, mid);
	MergeSortRecursion(A, mid+1, right);
	//合并
	Mergy(A, left, mid, right);
}


void MergeSortIteration(int A[], int len)    // 非递归(迭代)实现的归并排序(自底向上)
{
	int left, mid, right;// 子数组索引,前一个为A[left...mid]，后一个子数组为A[mid+1...right]
	for (int i = 1; i < len; i *= 2)        // 子数组的大小i初始为1，每轮翻倍
	{
		left = 0;
		while (left + i < len)              // 后一个子数组存在(需要归并)
		{
			mid = left + i - 1;
			right = mid + i < len ? mid + i : len - 1;// 后一个子数组大小可能不够
			Mergy(A, left, mid, right);
			left = right + 1;               // 前一个子数组索引向后移动
		}
	}
}

void Swap(int A[], int i, int j)
{
	int temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}

void Heapify(int A[], int i, int size)  // 从A[i]向下进行堆调整
{
	int left_child = 2 * i + 1;         // 左孩子索引
	int right_child = 2 * i + 2;        // 右孩子索引
	int max = i;                        // 选出当前结点与其左右孩子三者之中的最大值
	if (left_child < size && A[left_child] > A[max])
		max = left_child;
	if (right_child < size && A[right_child] > A[max])
		max = right_child;
	if (max != i)
	{
		Swap(A, i, max);                // 把当前结点和它的最大(直接)子节点进行交换
		Heapify(A, max, size);          // 递归调用，继续从当前结点向下进行堆调整
	}
}

int BuildHeap(int A[], int n)           // 建堆，时间复杂度O(n)
{
	int heap_size = n;
	for (int i = heap_size / 2 - 1; i >= 0; i--) // 从每一个非叶结点开始向下进行堆调整
		Heapify(A, i, heap_size);
	return heap_size;
}

void HeapSort(int A[], int n)
{
	int heap_size = BuildHeap(A, n);    // 建立一个最大堆
	while (heap_size > 1)   // 堆（无序区）元素个数大于1，未完成排序
	{
		// 将堆顶元素与堆的最后一个元素互换，并从堆中去掉最后一个元素
		// 此处交换操作很有可能把后面元素的稳定性打乱，所以堆排序是不稳定的排序算法
		Swap(A, 0, --heap_size);
		Heapify(A, 0, heap_size);     // 从新的堆顶元素开始向下进行堆调整，时间复杂度O(logn)
	}
}


int Partition(int A[], int left, int right)  // 划分函数
{
	int pivot = A[right];               // 这里每次都选择最后一个元素作为基准
	int tail = left - 1;                // tail为小于基准的子数组最后一个元素的索引
	for (int i = left; i < right; i++)  // 遍历基准以外的其他元素
	{
		if (A[i] <= pivot)              // 把小于等于基准的元素放到前一个子数组末尾
		{
			Swap(A, ++tail, i);
		}
	}
	Swap(A, tail + 1, right);           // 最后把基准放到前一个子数组的后边，剩下的子数组既是大于基准的子数组
	// 该操作很有可能把后面元素的稳定性打乱，所以快速排序是不稳定的排序算法
	return tail + 1;                    // 返回基准的索引
}

void QuickSort(int A[], int left, int right)
{
	if (left >= right)
		return;
	int pivot_index = Partition(A, left, right); // 基准的索引
	QuickSort(A, left, pivot_index - 1);
	QuickSort(A, pivot_index + 1, right);
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
	/*MergeSortRecursion(A, 0, length-1);*/
	//MergeSortIteration(A, length);
	/*HeapSort(A, length);*/
	QuickSort(A, 0, length - 1);
	return 0;
}