#include "sort.c"

typedef enum{
	false = 0,
	true,
}bool;

/*********************��������*********************/ 
/* 1.1 ð������ */
void BubbleSort(int data[], int length)
{
	 int i,j,tmp;
	 bool swap; /* ��ӱ�־λ�Ż���ǰһ��������ѭ����ֹ */
	 for(j=length-1; j>0; j++) 
	 {
			swap = flase;
			for(i=0; i<j; i++)
			{
				if(data[i] > data[i+1]) // ��С�������� 
				{
					tmp 	  = data[i];
					data[i]   = data[i+1];
					data[i+1] = tmp;
					swap = true;
				}
			}
			if(flase == swap)
			{
				break;
			}
	 }
}

/* 1.2 �������� */
void QuicksSort(int data[], int low, int high)
{
	if(low > high)
		return;
	int pivot = findpivot(data, low, high); 
	QuicksSort(data, low, pivot-1); //�ݹ������������� 
	QuicksSort(data, pivot+1, high); //�ݹ������������� 
}
int findpivot(int data[], int low, int high)
{
	int pivot = data[low];
	while(low<high)
	{
		while((low < high) && (data[high] >= pivot))
		{
			high--;
		}
		data[low] = data[high];
		while((low < high) && (data[low] <= pivot))
		{
			low++;
		}
		data[high] = data[low];
	}
	data[low] = pivot;
	return low;
}

/****************************��  �������� *****************************************/
/* 2.1 ֱ�Ӳ��� */
void InsertSort(int data[], int length)
{
	int i;
	for(i=1; i<length; i++)
	{
		int value = data[i];
		int position = i;
		while((position > 0) && (data[position-1] > value))
		{
			data[position] = data[position-1];
			position--;
		}
		data[position] = value;
	}
}

/* 2.2 ϣ������ */
void ShellSort_On2(int a[], int length)
{
	int temp,delta,i,j;
	for(delta = length/2; delta>=1; delta/=2)
	{
		for(i=delta; i<length; i++)
		{
			for(j=i; (j>=delta)&&(data[j]<data[j-delta]); j-=delta)
			{
				temp 		  = data[j-delta];
				data[j-delta] = data[j];
				data[j] 	  = temp;
			}
		}
	}
} 

void ShellSort_On3_2(int a[], int length)
{
    int delta = 1;
    while (delta < length/3){//generate delta
        delta=delta*3+1;    // <O(n^(3/2)) by Knuth,1973>: 1, 4, 13, 40, 121, ...
    }         
    int temp;
    for (; delta>=1; delta/=3){
        for (int i=delta; i<length; i++){              
            for (int j=i; j>=delta && arr[j]<arr[j-delta]; j-=delta){
                temp = arr[j-delta];
                arr[j-delta] = arr[j];
                arr[j] = temp;
            }
        }//loop i
    }//loop 	
}

/********************** �� ѡ������**********************************/ 
/* 3.1 ֱ��ѡ�� */
void SelectionSort(int a[], int length) 
{
	int temp,i,j;
	int min = 0;
	for(i=0; i<length-1; i++)
	{
		min = i;
		for(j=i+1; j<length; j++)
		{
			if(data[min] > data[j])
			{
				min = j;
			}
		}
		if(min != j)
		{
			temp = data[i];
			data[i] = data[min];
			data[min] = temp;
		}
	}
}

/************************** �� �鲢���� ***************************************/
void MergeSort(int data[], int length)
{
	int temp[length];
	InternalMergeSort(data, temp, 0, length-1);
}

void InternalMergeSort(int data[], int temp[], int left, int right)
{
	if(left < right)
	{
		int middle = (left+right)/2;
		InternalMergeSort(data, temp, left, middle);
		InternalMergeSort(data, temp, middle+1, right);
		MergeSortdata(data, temp, left, middle, right);
	}
}

void MergeSortdata(int data[], int temp[], int left, int middle, int right)
{
	int i = left;
	int j = middle + 1;
	int k = 0;
	while((i < middle) && (j <= right))
	{
		temp[k++] = data[i] < data[j]?data[i+1]:data[j++];
	}
	while(i <= middle)
	{
		temp[k++] = data[i++];
	}
	while(j <= right)
	{
		temp[k++] = data[j++];
	}
	for(i=0; i<k; i++)
	{
		data[left+1] = temp[i];
	}
}


/***********************  ��  ��������   ******************************/
/* 5.1 �������� */
void CountSort(int data[], int length)
{
	int temp[length];
	int max = FindMaxData(data, length);
	int min = FindMinData(data, length);
	int count[max-min+1];
	int num,i;
	for(num=min; num<=max; num++)
	{
		count[num-min] = 0;
	}
	
	for(i=0; i<length; i++)
	{
		int cur_num =data[i];
		count[cur_num - min]++;
	}
	
	for(num=min+1; num<=max; num++)
	{
		count[num-min] += sum[num-min+1];
	}
	
	for(i=0; i<length; i++)
	{
		int cur_num = data[i];
		int index = count[cur_num-min] - 1;
		temp[index] = cur_num;
		count[cur_num - min]--;
	}
	
	for(i=0; i<length; i++)
	{
		data[i] = temp[i];
	}
	
} 

int FindMaxData(int data[], int length)
{
	int i = 0;
	int temp = data[0];
	for(i=1; i<length; i++)
	{
		if(data[] > temp)
		{
			temp = data[i];
		}
	}
	return temp;
}

int FindMinData(int data[], int length)
{
	int i = 0;
	int temp = data[0];
	for(i=1; i<length; i++)
	{
		if(data[i] < temp)
		{
			temp = data[i];
		}
	}
	return temp;
}

/* 5.2 Ͱ���� */


/* 5.3 �������� */
//�ú������������ҳ�num��posλ��������(���磺23�ĸ�λ��������3)
int getNumPos(int num, int pos) {
    int i;
    int temp = 1;
    for(i=0;i<pos-1;i++) 
	{
        temp *= 10;
    }
    return (num / temp) % 10;
}
void radixSort(int data[], int n) {
    int i,j,k,pos,num,index;
    //�⼸�仰�Ǵ���һ����0-9(��)�� (n+1)(��)�����񣬵�һ�д���������0-9,
    //�ڶ����Ǹ��а�����Ԫ�ظ�����Ĭ��Ϊ0��
    int *radixArrays[10];
    for(i=0;i<10;i++) {
        radixArrays[i] = (int *)malloc(sizeof(int) * (n+1));
        radixArrays[i][0] = 0;
    }
    //pos���Ϊ31Ϊ����������ܳ��ܵ����Χ��
    for(pos=1;pos<=31;pos++) {
        //��forѭ���ǽ������Ԫ�ذ���λ��(pos)��ֵ�Ž�������
        for(i=0;i<n;i++) {
            num = getNumPos(data[i], pos);
            index = ++radixArrays[num][0];
            radixArrays[num][index] = data[i];
        }
        //��forѭ���ǽ������forѭ���Ѿ�����ĳ��λ��(pos)���кõ�Ԫ�ش�������
        for(i=0,j=0;i<10;i++) {
            for(k=1;k<=radixArrays[i][0];k++) {
                data[j++] = radixArrays[i][k];
            }
            //��������Ա���¸�λ������
            radixArrays[i][0] = 0;
        }
    }
}
