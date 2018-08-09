#include <iostream>
using namespace std;

//�����������ֵ�˳��
void Swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

//������������Ԫ��
void Traverse(int *a, int n)
{
	int i = 0;
	for (i; i < n; i++)
	{
		cout << "***" << a[i] ;
	}
	cout << endl;
}


//ð����������棨�ϸ����岻��ð������,ð�����������Ƚ�����Ԫ��)
//����򵥽�������
void BubbleSortInit(int *A, int n)
{
	int i = 0;
	for(i = 0; i < n-1; i++)
	{
		cout << "����ǰ˳��" << endl;
		Traverse(A, n);
		int j;
		for (j = i+1; j < n; j++ )
		{
			//�ϸ�������Сֵ
			if (A[i] > A[j])
			{
				Swap(&A[i], &A[j]);
			}
		}
		cout << "����ǰ˳��" << endl;
		Traverse(A, n);
	}
}

//ð������ ����
void BubbleSort_Up(int A[], int n)
{
	int i = 0;
	for (i; i < n-1; i++)
	{
		cout << "����ǰ˳��" << endl;
		Traverse(A, n);
		int j;
		for (j = n -1; j >= i; j--)
		{
			//��Сֵ�ϸ�
			if (A[j-1] > A[j])
			{
				Swap(&A[j-1], &A[j]);
			}
		}
		cout << "����ǰ˳��" << endl;
		Traverse(A, n);
	}
}

//ð������
//n:����ĳ��� �³�ʽ
void BubbleSortDown(int A[], int n)
{
	for(int i = 0; i < n-1; i++)
	{
		cout << "����ǰ˳��" << endl;
		Traverse(A, n);
		for(int j = 0; j < n-i-1; j++)
		{
			//�ϴ���³�
			if (A[j] > A[j+1])
			{
				Swap(&A[j], &A[j+1]);
			}
		}
		cout << "������˳��" << endl;
		Traverse(A, n);
	}
}


//ð������Ľ���__��β������(����ð������)
void CocktailSort(int A[], int n)
{
	int left = 0;
	int right = n -1;
	while (left < right)
	{
		cout << "�������ұ���ǰ˳��" << endl;
		Traverse(A, n);
		//�������ҽ���ð������
		for (int i = left; i < right; i++)
		{
			//�ϴ�ֵ����
			if (A[i] > A[i+1])
			{
				Swap(&A[i], &A[i+1]);
			}
		}
		right--;
		cout << "�������ұ�����˳��" << endl;
		Traverse(A, n);


		cout << "�����������ǰ˳��" << endl;
		Traverse(A, n);
		//�����������ð������
		
		int j;
		for(j = right; j > left; j-- )
		{
			//��Сֵ����
			if (A[j-1] > A[j])
			{
				Swap(&A[j-1], &A[j]);
			}
		}
		cout << "�������������˳��" << endl;
		Traverse(A, n);
		left++;
	}
}


//ð������Ľ���_������
void BubbleSort_flag(int A[], int n)
{
	bool flag = true;
	for(int i = 0; i < n-1 && flag; i++)
	{
		cout << "����ǰ˳��" << endl;
		Traverse(A, n);
		int j;
		for(j = n-1; j> i; j--)
		{
			flag = false;
			//�ϸ�ʽ
			//
			if (A[j-1] > A[j])
			{
				Swap(&A[j-1], &A[j]);
				flag = true;
			}
		}
		cout << "������˳��" << endl;
		Traverse(A, n);
	}

}

//��������
void InsertSort(int A[], int n)
{
	int i = 1;//ץ��
	for(i; i < n; i++)
	{
		cout << "����ǰ˳��" << endl;
		Traverse(A, n);
		int get = A[i];
		int j = i -1;
		while (j >= 0 && A[j] > get)
		{
			A[j+1] = A[j];
			j--;
		}
		A[j + 1] = get;
		cout << "������˳��" << endl;
		Traverse(A, n);
	}
}

//��������Ľ�
void InsertSortDichotomy(int A[], int n)
{
	int i = 1;
	for (i ; i < n; i++)
	{
		cout << "����ǰ˳��" << endl;
		Traverse(A, n);
		int get = A[i];
		int left = 0;
		int right = i-1;
		//���ַ���λ���Ƶ�λ��
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
		
		//�Ѿ���λ���Ƶ�λ�ã�������������λ�õ��ұ���������
		for(int j = i-1; j >= left; j--)
		{
			A[j+1] = A[j];
		}
		A[left] = get;	
		cout << "������˳��" << endl;
		Traverse(A, n);
	}
}


//��ϣ������Ҳ�еݼ���������
//��������ĸ�Ч�Ľ�
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
		//�����ڲ�������
		for (int i = h; i < n; i++)
		{
			cout << "����ǰ˳��" << endl;
			Traverse(A, n);
			int get = A[i];
			int j = i- h;
			while (j >= 0 && A[j] > get)
			{
				A[j + h] = A[j];
				j = j-h;
			}
			A[j+h] = get;
			cout << "������˳��" << endl;
			Traverse(A, n);
		}
		//***********************************************************
		h = (h - 1)/3;
	}
	
}

//�鲢����:1���ݹ�ʵ�ֵĹ鲢���� 2���ǵݹ�ʵ�ֵĹ鲢����

//�ϲ�����������õ�����
void Mergy(int A[], int left, int mid, int right)
{
	//ǰ������
	//
	cout << "mergy" <<endl;
	cout << "left:  " << left <<"  mid:  " << mid << "  right:  " << right << endl;
	int len = right - left + 1;
	int i = left;//����1�ĳ�ʼλ��
	int j = mid+1;//����2�ĳ�ʼλ��
	//�����ռ�len
	int *temp = new int[len];
	int index = 0;
	//��������
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
	//���鸴�Ƶ�A��
	int k;
	for(k = 0; k < len; k++)
	{
		A[left++] = temp[k];
	}
}

//�ݹ�ʵ�ֹ鲢����
//�Զ�����
void MergeSortRecursion(int A[], int left, int right)
{
	cout << "recursion" << endl;
	cout << "left:  " << left << "  right  " << right << endl;
	//�ݹ鿪ʼ����
	if (left == right)
	{
		return;
	}
	//�ݹ�����
	int mid = (left + right)/2;
	MergeSortRecursion(A, left, mid);
	MergeSortRecursion(A, mid+1, right);
	//�ϲ�
	Mergy(A, left, mid, right);
}

int main()
{
	int A[] = {3,2,4,1,5,7};
	//���鳤��
	int length = sizeof(A)/sizeof(A[0]);
	//ð������
	/*BubbleSortInit(A, length);*/
	/*BubbleSort_Up(A, length);*/
	//BubbleSort(A, length);
	//CocktailSort(A, length);
	/*BubbleSort_flag(A, length);*/
	//InsertSort(A, length);
	/*ShellSort(A, length);*/
	MergeSortRecursion(A, 0, length-1);
	return 0;
}